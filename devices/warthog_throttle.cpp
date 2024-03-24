#include "twcs_throttle.h"

vector<vector<string>> twcs_throttle_axes(void){
vector<vector<string>> twcs_throttle_axs = {{"0", "Slew Control Left/Right","images/b687_slewlr.png" },
				              {"1", "Slew Control Up/Down","images/b687_slewud.png" },
				              {"2", "Right Throttle","images/b687_rt.png" },
      					      {"3", "Left Throttle","images/b687_lt.png" },
			       	 	      {"4", "Incr/Decr", "images/b687_indec.png" },
       				 	      {"5", "Coolie-Left/Right", "images/b687_coollr.png" },
        				      {"6", "Coolie-Up/Down", "images/b687_coolud.png"}};
return twcs_throttle_axs;
}

vector<vector<string>> twcs_throttle_buttons(void){
vector<vector<string>> twcs_throttle_butts = {{"0", "Coolie In", "images/b687_" },
						{"1","Right Thumb In", "images/b687_rthumbin.png" },
						{"2","Right Thumb Hat-Up", "images/b687_rthumbup.png" },
						{"3","Right Thumb Hat-Forward", "images/b687_rthumbfwd.png" },
						{"4","Right Thumb Hat-Down", "images/b687_rthumbdn.png" },
						{"5","Right Thumb Hat-Back", "images/b687_rthumbbk.png" },
						{"6","Speed Brake Forwards", "images/b687_spdbkfwd.png" },
						{"7","Speed Brake Backwards", "images/b687_spdbk.png" },
						{"8","Boat Switch Forwards", "images/b687_bsfwd.png" },
						{"9","Boat Switch Backwards", "images/b687_bsbk.png" },
						{"10","China Hat Forwards", "images/b687_chfwd.png" },
						{"11","China Hat Backwards", "images/b687_chbk.png" },
						{"12","Pinky Switch Forwards", "images/b687_psfwd.png" },
						{"13","Pinky Switch Backwards", "images/b687_psbk.png" },
						{"14","Left Throttle Button", "images/b687_ltb.png" },
						{"15","Engine Flow L Override", "images/b687_eflo.png" },
						{"16","Engine Flow R Override", "images/b687_efro.png" },
						{"17","Left Engine Operate Backwards", "images/b687_leobk.png" },
						{"18","Right Engine Operate Backwards", "images/b687_reobk.png" },
						{"19","APU START", "images/b687_apust.png" },
						{"20","L/G WRN", "images/b687_lgwrn.png" },
						{"21","FLAPS UP", "images/b687_flup.png" },
						{"22","FLAPS DN", "images/b687_fldn.png" },
						{"23","EAC ARM", "images/b687_eacarm.png" },
						{"24","RDR ALTM NRM", "images/b687_rdrnrm.png" },
						{"25","AUTOPILOT ENGAGE/DISENGAGE", "images/b687_apeng.png" },
						{"26","PATH", "images/b687_path.png" },
						{"27","ALT", "images/b687_alt.png" },
						{"28","Unknown", "images/b687_null.png" },
						{"29","Unknown", "images/b687_null.png" },
						{"30","Left Engine Operate Forwards", "images/b687_leof.png" },
						{"31","Right Engine Operate Forwards", "images/b687_reof.png" }};
return twcs_throttle_butts;
}
