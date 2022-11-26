#include "warthog_stick.h"

vector<vector<string>> warthog_stick_axes(void){
	vector<vector<string>> warthog_stick_axs = {{"0", "X-Axis", "images/.png"},
	        			   {"1", "Y-Axis", "images/.png"},
					   {"2", "Trim Hat-Left/Right", "images/.png"},
					   {"3", "Trim Hat-Up/Down", "images/.png"}};
return warthog_stick_axs;
}

vector<vector<string>> warthog_stick_buttons(void){
	vector<vector<string>> warthog_stick_butts = {{"0", "Gun Trigger 1st Stage", "images/.png"},
						{"1","Weapon Release", "images/.png"},
						{"2","Nosewheel", "images/.png"},
						{"3","Pinky Switch", "images/.png"},
						{"4","Master Mode", "images/.png"},
						{"5","Gun Trigger 2nd Stage", "images/.png"},
						{"6","TMS Up", "images/.png"},
						{"7","TMS Right", "images/.png"},
						{"8","TMS Down", "images/.png"},
						{"9","TMS Left", "images/.png"},
						{"10","DMS Up", "images/.png"},
						{"11","DMS Right", "images/.png"},
						{"12","DMS Down", "images/.png"},
						{"13","DMS Left", "images/.png"},
						{"14","CMS Forward", "images/.png"},
						{"15","CMS Right", "images/.png"},
						{"16","CMS Backwards", "images/.png"},
						{"17","CMS Left", "images/.png"},
						{"18","CMS Push", "images/.png"}};
return warthog_stick_butts;
}
