#if defined _locolib_included
 #endinput
#endif
#define _locolib_included

#include <cstrike>

#define any(%0)		view_as<any>(%0)
#define int(%0)		view_as<int>(%0)
#define char(%0)	view_as<char>(%0)
#define bool(%0)	view_as<bool>(%0)

#include "locolib/entity"
#include "locolib/weapon"
#include "locolib/weaponid"