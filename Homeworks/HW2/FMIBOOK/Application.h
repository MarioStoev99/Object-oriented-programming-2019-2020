#include "User.h"
#include "Moderator.h"
#include "Administrator.h"
#include "myNameSpace.h"
#include <typeinfo>
#include "UsersHandling.h"
#include "PublicationsHandling.h"
#include "PublicationLink.h"
#include "PublicationPicture.h"
#include "PublicationText.h"
#pragma once
class Application
{
private : 
	UsersHandling controlUsers;
	PublicationsHandling controlPublications;
public : 
	Application() = default;
	Application(const Application&) = delete;
	Application& operator=(const Application&) = delete;
	void startApp();
};

