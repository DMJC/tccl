#include "warthog_throttle.h"

vector<vector<string>> warthog_throttle_axes(void){
vector<vector<string>> warthog_throttle_axs = {{"0", "Slew Control Left/Right","images/slewlr.png" },
				              {"1", "Slew Control Up/Down","images/slewud.png" },
				              {"2", "Right Throttle","images/rt.png" },
      					      {"3", "Left Throttle","images/lt.png" },
			       	 	      {"4", "Incr/Decr", "images/indec.png" },
       				 	      {"5", "Coolie-Left/Right", "images/coollr.png" },
        				      {"6", "Coolie-Up/Down", "images/coolud.png"}};
return warthog_throttle_axs;
}

vector<vector<string>> warthog_throttle_buttons(void){
vector<vector<string>> warthog_throttle_butts = {{"0", "Coolie In", "images/" },
						{"1","Right Thumb In", "images/rthumbin.png" },
						{"2","Right Thumb Hat-Up", "images/rthumbup.png" },
						{"3","Right Thumb Hat-Forward", "images/rthumbfwd.png" },
						{"4","Right Thumb Hat-Down", "images/rthumbdn.png" },
						{"5","Right Thumb Hat-Back", "images/rthumbbk.png" },
						{"6","Speed Brake Forwards", "images/spdbkfwd.png" },
						{"7","Speed Brake Backwards", "images/spdbk.png" },
						{"8","Boat Switch Forwards", "images/bsfwd.png" },
						{"9","Boat Switch Backwards", "images/bsbk.png" },
						{"10","China Hat Forwards", "images/chfwd.png" },
						{"11","China Hat Backwards", "images/chbk.png" },
						{"12","Pinky Switch Forwards", "images/psfwd.png" },
						{"13","Pinky Switch Backwards", "images/psbk.png" },
						{"14","Left Throttle Button", "images/ltb.png" },
						{"15","Engine Flow L Override", "images/eflo.png" },
						{"16","Engine Flow R Override", "images/efro.png" },
						{"17","Left Engine Operate Backwards", "images/leobk.png" },
						{"18","Right Engine Operate Backwards", "images/reobk.png" },
						{"19","APU START", "images/apust.png" },
						{"20","L/G WRN", "images/lgwrn.png" },
						{"21","FLAPS UP", "images/flup.png" },
						{"22","FLAPS DN", "images/fldn.png" },
						{"23","EAC ARM", "images/eacarm.png" },
						{"24","RDR ALTM NRM", "images/rdrnrm.png" },
						{"25","AUTOPILOT ENGAGE/DISENGAGE", "images/apeng.png" },
						{"26","PATH", "images/path.png" },
						{"27","ALT", "images/alt.png" },
						{"28","Unknown", "images/null.png" },
						{"29","Unknown", "images/null.png" },
						{"30","Left Engine Operate Forwards", "images/leof.png" },
						{"31","Right Engine Operate Forwards", "images/reof.png" }};
return warthog_throttle_butts;
}
