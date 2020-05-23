#include "Application.h"
void Application::startApp()
{
	String command, actor, action, subject;
	int age;
	while (true)
	{
		cout << "$: ";
			getline(cin, command);
		int spaces = AdditionalMethods::countSpaces(command);
		if (spaces == 0)
		{
			if (command == "quit")
				break;
			if (command == "info")
				controlUsers.info();
		}
		else if (spaces == 1)
			cout << "Unknown command" << endl;
		else if (spaces >= 3)
		{
			AdditionalMethods::commandForThreeSpaces(command, actor, action, subject, age);
			size_t indexOfUserInArray = controlUsers.findPosUserInArray(actor);
			if (indexOfUserInArray == -1)
			{
				cout << "This user not exist" << endl;
				continue;
			}
			bool haveRights = controlUsers.haveRights(indexOfUserInArray);
			if (action == "add_moderator" && haveRights)
			{
				User* newMember = new Moderator(subject, age);
				controlUsers.addMember(newMember);
			}
			else if (action == "add_user" && haveRights)
			{
			User* newMember = new User(subject, age);
				controlUsers.addMember(newMember);
			}
			else if (action == "post")
			{
				size_t actorIndex = controlUsers.findPosUserInArray(actor);
				if (actorIndex == -1)
				{
					cout << "No such user : " << actor << endl;
					continue;
				}
				if (controlUsers.blockUser(actorIndex))
				{
					cout << "Post not created - user blocked!" << endl;
					continue;
				}
				controlUsers.increasePersonalPosts(actorIndex);
				if (subject == "[image]")
				{
					Publication* newPublication = new PublicationPicture(actor, command);
					controlPublications.addPublication(newPublication);
				}
				else if (subject == "[url]")
				{
					Publication* newPublication = new PublicationLink(actor, command);
					controlPublications.addPublication(newPublication);
				}
				else if (subject == "[text]")
				{
					Publication* newPublication = new PublicationText(actor, command);
					controlPublications.addPublication(newPublication);
				}
				else
				{
					cout << "Unknown command!" << endl;
				}
			}
		}
		else if (spaces == 2)
		{
			AdditionalMethods::commandForTwoSpaces(command, actor, action, subject);
			size_t indexOfUserInArray = controlUsers.findPosUserInArray(actor);
			bool haveRights = controlUsers.haveRights(indexOfUserInArray);
			if (indexOfUserInArray == -1)
			{
				cout << "This user not exist" << endl;
				continue;
			}
			if (controlUsers.blockUser(indexOfUserInArray))
			{
				cout << "Post not created - user blocked!" << endl;
				continue;
			}
			if (action == "block")
			{
				controlUsers.blockorUnblock(actor,subject,1);
			}
			else if (action == "unblock")
			{
				controlUsers.blockorUnblock(actor, subject, 0);
			}
			else if (action == "rename")
			{
				controlUsers.rename(actor, subject);
			}
			else if (action == "remove_user" && haveRights)
			{
				controlUsers.removeMember(subject, age);
				controlPublications.removeUsersPosts(subject);
			}
			else if (action == "remove_post")
			{
				int id = 0;
				if (AdditionalMethods::isDigit(subject))
					id = stoi(subject);
				if (controlUsers.haveRights(indexOfUserInArray))
					controlPublications.removePost(id);
				else if (controlPublications.correctUserRemove(actor, id))
					controlPublications.removePost(id);
				else
					cout << "You don't have rights to this post" << endl;
			}
			else if (action == "view_post")
			{
				int id = 0;
				if (AdditionalMethods::isDigit(subject))
				{
					id = stoi(subject);
					controlPublications.generatePublication(id);
				}
			}
			else if (action == "view_all_posts")
			{
				controlPublications.generatePublication(subject);
			}
			else
				cout << "Unknown command!" << endl;;
		}
	}
}
