#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleUI.h"
#include "ModuleCollision.h"
#include "ModulePlayer2.h"
#include "ModuleJudge.h"

ModulePlayer::ModulePlayer()
{
	//animations
	{
		//Haohmaru 
		{
			 /*
			//idle animation
			{
				idle.PushBack({ 16,22,71,109 }, 0.3f);
				idle.PushBack({ 92,22,72,109 }, 0.3f);
				idle.PushBack({ 168,22,71,109 }, 0.3f);
				idle.PushBack({ 245,20,72,111 }, 0.3f);
				idle.PushBack({ 322,18,72,113 }, 0.3f);
				idle.PushBack({ 399,19,72,112 }, 0.3f);
				idle.PushBack({ 476,19,74,112 }, 0.3f);
				idle.PushBack({ 554,19,74,112 }, 0.3f);
				idle.PushBack({ 630,19,73,112 }, 0.3f);
				idle.PushBack({ 245,20,72,111 }, 0.3f);
				idle.PushBack({ 322,18,72,113 }, 0.3f);
				idle.PushBack({ 399,19,72,112 }, 0.3f);
				idle.loop = true;
			}

			//forward animation
			{
				forward.PushBack({ 15,496,70,112 }, 0.4f);
				forward.PushBack({ 89,496,70,112 }, 0.4f);
				forward.PushBack({ 163,499,76,109 }, 0.4f);
				forward.PushBack({ 243,499,76,109 }, 0.4f);
				forward.PushBack({ 322,499,76,109 }, 0.4f);
				forward.PushBack({ 402,496,69,112 }, 0.4f);
				forward.PushBack({ 475,496,69,112 }, 0.4f);
				forward.PushBack({ 548,496,69,112 }, 0.4f);
				forward.PushBack({ 621,492,59,116 }, 0.4f);
				forward.PushBack({ 684,492,59,116 }, 0.4f);
				forward.PushBack({ 747,492,59,116 }, 0.4f);
				forward.PushBack({ 810,492,57,116 }, 0.4f);
				forward.PushBack({ 871,490,57,118 }, 0.4f);
				forward.PushBack({ 933,490,56,118 }, 0.4f);
				forward.PushBack({ 994,490,61,118 }, 0.4f);
				forward.PushBack({ 1060,492,61,116 }, 0.4f);
				forward.PushBack({ 1126,492,61,116 }, 0.4f);
			}

			//backward animation
			{
				backward.PushBack({ 624,608,82,121 }, 0.4f);//9
				backward.PushBack({ 711,608,82,121 }, 0.4f);//10
				backward.PushBack({ 798,608,82,121 }, 0.4f);//11
				backward.PushBack({ 884,608,82,121 }, 0.4f);//12
				backward.PushBack({ 15,614,74,114 }, 0.4f); //1
				backward.PushBack({ 94,614,74,114 }, 0.4f); //2
				backward.PushBack({ 173,614,74,114 }, 0.4f); //3
				backward.PushBack({ 264,610,68,118 }, 0.4f); //4
				backward.PushBack({ 337,610,68,118 }, 0.4f); //5
				backward.PushBack({ 410,612,68,117 }, 0.4f); //6
				backward.PushBack({ 482,609,67,121 }, 0.4f);//7
				backward.PushBack({ 553,608,67,121 }, 0.4f);//8
				backward.PushBack({ 971,608,69,122 }, 0.4f);//13
				backward.PushBack({ 1045,608,69,121 }, 0.4f);//14
				backward.PushBack({ 1119,608,69,120 }, 0.4f);//15
				backward.PushBack({ 1193,614,74,114 }, 0.4f);//16
				backward.PushBack({ 1272,614,74,114 }, 0.4f);//17
				backward.PushBack({ 1351,614,74,114 }, 0.4f);//18
			}

			//jump neutral animation
			{
				jump_neutral.PushBack({ 15, 371, 60, 112 }, 0.2f); //1
				jump_neutral.PushBack({ 80, 371, 60, 112 }, 0.2f); //2
				jump_neutral.PushBack({ 145, 371, 60, 112 }, 0.2f); //3
				jump_neutral.PushBack({ 209, 371, 75, 92 }, 0.2f);
				jump_neutral.PushBack({ 288, 371, 75, 92 }, 0.2f);
				jump_neutral.PushBack({ 367, 371, 75, 92 }, 0.2f);
				jump_neutral.PushBack({ 446, 371, 78, 83 }, 0.2f);
				jump_neutral.PushBack({ 209, 371, 75, 92 }, 0.2f);
				jump_neutral.PushBack({ 288, 371, 75, 92 }, 0.2f);
				jump_neutral.PushBack({ 367, 371, 75, 92 }, 0.2f);
				jump_neutral.PushBack({ 15, 371, 60, 112 }, 0.2f); //1
				jump_neutral.PushBack({ 80, 371, 60, 112 }, 0.2f);
				jump_neutral.PushBack({ 145, 371, 60, 112 }, 0.2f);
				jump_neutral.PushBack({ 527, 371, 68, 112 }, 0.2f); //8
				jump_neutral.PushBack({ 601, 371, 68, 112 }, 0.2f); //9
				jump_neutral.PushBack({ 674, 371, 68, 112 }, 0.2f); //10
			}

			//jump forward animation
			{
				jump_forward.PushBack({ 15, 1362, 63, 130 }, 0.3f);
				jump_forward.PushBack({ 83, 1362, 63, 130 }, 0.3f);
				jump_forward.PushBack({ 151, 1362, 63, 130 }, 0.3f);
				jump_forward.PushBack({ 224, 1362, 74, 93 }, 0.3f);
				jump_forward.PushBack({ 307, 1362, 74, 93 }, 0.3f);
				jump_forward.PushBack({ 391, 1362, 74, 93 }, 0.3f);
				jump_forward.PushBack({ 478, 1362, 62, 81 }, 0.3f);
				jump_forward.PushBack({ 559, 1362, 62, 81 }, 0.3f);
				jump_forward.PushBack({ 631, 1362, 62, 81 }, 0.3f);
				jump_forward.PushBack({ 706, 1362, 80, 62 }, 0.3f);
				jump_forward.PushBack({ 799, 1362, 80, 62 }, 0.3f);
				jump_forward.PushBack({ 981, 1362, 62, 81 }, 0.3f);
				jump_forward.PushBack({ 1066, 1362, 62, 81 }, 0.3f);
				jump_forward.PushBack({ 1152, 1362, 62, 81 }, 0.3f);
				jump_forward.PushBack({ 1226, 1362, 80, 62 }, 0.3f);
				jump_forward.PushBack({ 1312, 1362, 80, 62 }, 0.3f);
				jump_forward.PushBack({ 1407, 1362, 80, 62 }, 0.3f);
				jump_forward.PushBack({ 1509, 1362, 77, 85 }, 0.3f);
				jump_forward.PushBack({ 1595, 1362, 77, 85 }, 0.3f);
				jump_forward.PushBack({ 1686, 1362, 77, 85 }, 0.3f);
				jump_forward.loop = false;
			}

			//jump backward animation
			{
				jump_backward.PushBack({ 15, 1492, 63, 112 }, 0.3f);
				jump_backward.PushBack({ 83, 1492, 63, 112 }, 0.3f);
				jump_backward.PushBack({ 151, 1492, 63, 112 }, 0.3f);
				jump_backward.PushBack({ 224, 1492, 74, 93 }, 0.3f);
				jump_backward.PushBack({ 307, 1492, 74, 93 }, 0.3f);
				jump_backward.PushBack({ 391, 1492, 74, 93 }, 0.3f);
				jump_backward.PushBack({ 478, 1492, 80, 61 }, 0.3f);
				jump_backward.PushBack({ 566, 1492, 80, 61 }, 0.3f);
				jump_backward.PushBack({ 661, 1492, 80, 61 }, 0.3f);
				jump_backward.PushBack({ 757, 1492, 62, 80 }, 0.3f);
				jump_backward.PushBack({ 842, 1492, 62, 80 }, 0.3f);
				jump_backward.PushBack({ 927, 1492, 62, 80 }, 0.3f);
				jump_backward.PushBack({ 1013, 1492, 80, 61 }, 0.3f);
				jump_backward.PushBack({ 1105, 1492, 80, 61 }, 0.3f);
				jump_backward.PushBack({ 1195, 1492, 80, 61 }, 0.3f);
				jump_backward.PushBack({ 1286, 1492, 62, 80 }, 0.3f);
				jump_backward.PushBack({ 1367, 1492, 62, 80 }, 0.3f);
				jump_backward.PushBack({ 1436, 1492, 62, 80 }, 0.3f);
				jump_backward.PushBack({ 1509, 1492, 77, 85 }, 0.3f);
				jump_backward.PushBack({ 1595, 1492, 77, 85 }, 0.3f);
				jump_backward.PushBack({ 1686, 1492, 77, 85 }, 0.3f);
				jump_backward.loop = false;
			}

			//punch animation
			{
				punch.PushBack({ 14, 236, 69, 130 }, 0.5f);
				punch.PushBack({ 87, 236, 69, 130 }, 0.3f);
				punch.PushBack({ 164, 235, 79, 127 }, 0.3f);
				punch.PushBack({ 243, 236, 79, 127 }, 0.5f);
				punch.PushBack({ 331, 236, 79, 127 }, 0.5f);
				punch.PushBack({ 410, 236, 129, 127 }, 0.5f);
				punch.PushBack({ 545, 236, 130, 127 }, 0.5f);
				punch.PushBack({ 679, 236, 130, 127 }, 0.5f);
				punch.PushBack({ 814, 236, 129, 127 }, 0.5f); //9
				punch.PushBack({ 946, 236, 130, 127 }, 0.5f);
				punch.PushBack({ 1081, 236, 130, 127 }, 0.5f);
				punch.PushBack({ 1213, 236, 120, 127 }, 0.5f);
				punch.PushBack({ 1337, 236, 120, 127 }, 0.5f);
				punch.PushBack({ 1461, 236, 83, 127 }, 0.8f);
				punch.PushBack({ 1548, 236, 83, 127 }, 6.8f);
				punch.PushBack({ 1635, 236, 83, 127 }, 6.8f); //16
				punch.PushBack({ 1721, 236,131, 127 }, 6.7f);
				punch.PushBack({ 1856, 236, 131, 127 }, 6.7f);
				punch.loop = false;
			}


			//kick animation
			{
				kick.PushBack({ 16,137,66,95 }, 0.8f); //initial kick frames
				kick.PushBack({ 87,137,66,95 }, 0.8f);
				kick.PushBack({ 158,137,66,95 }, 0.8f);
				kick.PushBack({ 229,134,86,98 }, 0.6f); //final kick frames
				kick.PushBack({ 320,134,86,98 }, 0.6f);
				kick.PushBack({ 411,134,86,98 }, 0.6f);
				kick.PushBack({ 16,137,66,95 }, 0.7f); //initial kick frames
				kick.PushBack({ 87,137,66,95 }, 0.7f);
				kick.PushBack({ 158,137,66,95 }, 0.7f);
				kick.loop = false;
			}

			//get hit animation 2
			{
				hit.PushBack({ 14, 1616, 78, 100 }, 0.3f);
				hit.PushBack({ 105, 1616, 78, 100 }, 0.3f);
				hit.PushBack({ 195, 1616, 78, 100 }, 0.3f);
				hit.PushBack({ 282, 1616, 77, 94 }, 0.3f);
				hit.PushBack({ 367, 1616, 77, 94 }, 0.3f);
				hit.PushBack({ 452, 1616, 77, 94 }, 0.3f);
				hit.PushBack({ 14, 1616, 78, 100 }, 6.3f);
				hit.PushBack({ 105, 1616, 78, 100 }, 6.3f);
				hit.PushBack({ 195, 1616, 78, 100 }, 6.3f);
				hit.loop = false;
			}

			//crouch animation
			{
				//Crouch Down
				crouch_down.PushBack({ 15, 1239, 68, 110 }, 0.5f);
				crouch_down.PushBack({ 94, 1239, 68, 110 }, 0.5f);
				crouch_down.PushBack({ 180, 1239, 68, 110 }, 0.5f);
				crouch_down.PushBack({ 299, 1273, 88, 76 }, 0.5f);
				crouch_down.PushBack({ 431, 1273, 88, 76 }, 0.5f);
				crouch_down.PushBack({ 557, 1273, 88, 76 }, 0.5f);
				crouch_down.loop = false;

				//Crouch Up
				crouch_up.PushBack({ 180, 1239, 68, 110 }, 0.9f);
				crouch_up.PushBack({ 94, 1239, 68, 110 }, 0.9f);
				crouch_up.PushBack({ 15, 1239, 68, 110 }, 0.9f);
				crouch_up.loop = false;
			}

			//crouch punch
			{
				crouch_punch.PushBack({ 15, 1718, 100, 93 }, 0.6f);
				crouch_punch.PushBack({ 102, 1718, 104, 93 }, 0.6f);
				crouch_punch.PushBack({ 210, 1718, 109, 93 }, 0.6f);
				crouch_punch.PushBack({ 324, 1718, 155, 90 }, 0.6f);
				crouch_punch.PushBack({ 476, 1718, 155, 90 }, 0.6f);
				crouch_punch.PushBack({ 640, 1718, 155, 91 }, 0.6f);
				crouch_punch.PushBack({ 792, 1718, 154, 92 }, 0.6f);
				crouch_punch.PushBack({ 953, 1718, 150, 94 }, 0.6f);
				crouch_punch.PushBack({ 1129, 1718, 150, 93 }, 0.6f);
				crouch_punch.PushBack({ 1287, 1718, 111, 93 }, 0.6f);
				crouch_punch.PushBack({ 1411, 1718, 111, 93 }, 0.6f);
				crouch_punch.PushBack({ 1539, 1718, 111, 93 }, 0.6f);
				crouch_punch.PushBack({ 1660, 1718, 111, 93 }, 0.6f);
				crouch_punch.PushBack({ 1786, 1718, 111, 93 }, 0.6f);
				crouch_punch.PushBack({ 1901, 1718, 109, 93 }, 0.6f);
				crouch_punch.loop = false;
			}

			//crouch kick
			{
				crouch_kick.PushBack({ 12, 1830, 74, 77 }, 0.3f);
				crouch_kick.PushBack({ 106, 1828, 74, 77 }, 0.3f);
				crouch_kick.PushBack({ 203, 1826, 79, 81 }, 0.3f);
				crouch_kick.PushBack({ 300, 1826, 79, 81 }, 0.3f);
				crouch_kick.PushBack({ 395, 1835, 99, 73 }, 0.3f);
				crouch_kick.PushBack({ 513, 1835, 99, 73 }, 0.3f);
				crouch_kick.PushBack({ 643, 1825, 79, 80 }, 0.6f);
				crouch_kick.PushBack({ 751, 1825, 79, 80 }, 0.6f);
				crouch_kick.loop = false;
			}

			//twister animation
			{
				twister.PushBack({ 15, 798, 90, 90 }, 0.6f);
				twister.PushBack({ 106, 798, 90, 90 }, 0.6f);
				twister.PushBack({ 197, 798, 90, 90 }, 0.6f);
				twister.PushBack({ 289, 798, 71, 90 }, 0.6f);
				twister.PushBack({ 362, 798, 71, 90 }, 0.6f);
				twister.PushBack({ 435, 803, 74, 86 }, 0.6f);
				twister.PushBack({ 511, 803, 74, 86 }, 0.6f);
				twister.PushBack({ 586, 795, 59, 94 }, 0.6f);
				twister.PushBack({ 646, 795, 59, 94 }, 0.6f);
				twister.PushBack({ 709, 788, 93, 101 }, 0.6f);
				twister.PushBack({ 809, 788, 93, 101 }, 0.6f);
				twister.PushBack({ 909, 788, 93, 101 }, 0.6f);
				twister.PushBack({ 1006, 734, 62, 155 }, 0.6f);
				twister.PushBack({ 1071, 734, 62, 155 }, 0.6f);
				twister.PushBack({ 1138, 734, 62, 155 }, 0.6f);
				twister.PushBack({ 1203, 787, 100, 102 }, 0.6f);
				twister.PushBack({ 1313, 787, 100, 102 }, 0.6f);
				twister.PushBack({ 1429, 787, 100, 102 }, 0.6f);
				twister.PushBack({ 1543, 795, 98, 94 }, 0.6f);
				twister.PushBack({ 1646, 795, 98, 94 }, 0.6f);
				twister.PushBack({ 1749, 795, 98, 94 }, 0.6f);
				twister.PushBack({ 15, 923, 104, 93 }, 0.6f);
				twister.PushBack({ 121, 923, 104, 93 }, 0.6f);
				twister.PushBack({ 228, 923, 104, 93 }, 0.6f);
				twister.PushBack({ 337, 923, 84, 93 }, 0.6f);
				twister.PushBack({ 425, 923, 84, 93 }, 0.6f);
				twister.PushBack({ 512, 923, 84, 93 }, 0.6f);
				twister.PushBack({ 599, 896, 72, 120 }, 0.6f);
				twister.PushBack({ 673, 896, 72, 120 }, 0.6f);
				twister.PushBack({ 748, 896, 72, 120 }, 0.6f);
				twister.loop = false;

				//Twister animation (only the twister)
				twisterAlone.loop = false;
			}

			//die
			{
				die.PushBack({ 852,0,108,54 });
			}

			//en garde
			{
				en_garde.PushBack({ 14, 1921, 74,113 }, 0.15f);
				en_garde.PushBack({ 95, 1921, 78,113 }, 0.15f);
				en_garde.PushBack({ 182, 1921, 79,113 }, 0.15f);
				en_garde.PushBack({ 264, 1921, 79,113 }, 0.15f);
				en_garde.PushBack({ 346, 1921, 81,113 }, 0.15f);
				en_garde.PushBack({ 433, 1921, 78,113 }, 0.15f);
				en_garde.PushBack({ 517, 1921, 79,113 }, 0.15f);
				en_garde.PushBack({ 595, 1921, 74,113 }, 0.15f);
				en_garde.PushBack({ 677, 1921, 73,113 }, 0.15f);
				en_garde.PushBack({ 164, 235, 79, 127 }, 0.15f);
				en_garde.PushBack({ 243, 236, 79, 127 }, 0.15f);
				//punch
				en_garde.PushBack({ 1721, 236,131, 127 }, 0.4f);
				en_garde.PushBack({ 1856, 236, 131, 127 }, 0.4f);
				en_garde.PushBack({ 1461, 236, 83, 127 }, 0.4f);
				en_garde.PushBack({ 1721, 236,131, 127 }, 0.4f);
				en_garde.loop = false;
			}


			//win animation
			{
				win.PushBack({ 49, 2072, 76, 177 }, 0.2f);
				win.PushBack({ 146, 2072, 76, 177 }, 0.2f);
				win.PushBack({ 250, 2079, 90, 170 }, 0.2f);
				win.PushBack({ 340, 2071, 90, 178 }, 0.2f);
				win.PushBack({ 440, 2040, 76, 209 }, 0.2f);
				win.PushBack({ 538, 2040, 76, 209 }, 0.2f);
				win.PushBack({ 631, 2040, 74, 209 }, 0.2f);
				win.PushBack({ 731 , 2040, 74, 209 }, 0.2f);
				win.PushBack({ 827, 2040, 74, 209 }, 0.2f);
				win.PushBack({ 923, 2040, 74, 209 }, 0.2f);
				win.PushBack({ 1025, 2131, 74, 118 }, 0.2f);
				win.PushBack({ 1125, 2146, 49, 102 }, 0.2f);
				win.PushBack({ 1182, 2143, 96, 106 }, 0.2f);
				win.PushBack({ 1288, 2143, 96, 106 }, 0.2f);
				win.PushBack({ 1409, 2144, 96, 106 }, 0.2f);
				win.PushBack({ 1515, 2144, 96, 106 }, 0.2f);
				win.PushBack({ 1614, 2143, 96, 106 }, 0.2f);
				win.PushBack({ 1723, 2144, 96, 106 }, 0.2f);
				win.PushBack({ 1838, 2143, 97, 106 }, 0.2f);
				win.PushBack({ 28, 2359, 96, 106 }, 0.2f);
				win.PushBack({ 140, 2359, 96, 106 }, 0.2f);
				win.PushBack({ 260, 2359, 98, 106 }, 0.2f);
				win.PushBack({ 380, 2359, 96, 106 }, 0.2f);
				win.PushBack({ 482, 2359, 96, 106 }, 0.2f);
				win.PushBack({ 1614, 2143, 96, 106 }, 0.2f);
				win.PushBack({ 678, 2359, 96, 106 }, 0.2f);
				win.PushBack({ 803, 2256, 98, 209 }, 0.2f);
				win.PushBack({ 910, 2256, 98, 209 }, 0.2f);
				win.PushBack({ 1001, 2256, 96, 209 }, 0.2f);
				win.PushBack({ 1100, 2256, 96, 209 }, 0.2f);
				win.PushBack({ 1289, 2256, 96, 209 }, 0.2f);
				win.PushBack({ 1409, 2256, 100, 209 }, 0.2f);
				win.PushBack({ 1524, 2256, 100, 209 }, 0.2f);
				win.PushBack({ 1628, 2256, 96, 209 }, 0.2f);
				win.PushBack({ 1744, 2256, 96, 209 }, 0.2f);
				//win.PushBack({1840, 2256, 96, 209}, 0.2f);
				//win.PushBack({49, 2488, 96, 190}, 0.2f);
				//win.PushBack({158, 2498, 96, 180}, 0.2f);
				//win.PushBack({255, 2503, 96, 175}, 0.2f);
				//win.PushBack({356, 2513, 96, 165}, 0.2f);
				//win.PushBack({452, 2521, 96, 157}, 0.2f);
				//win.PushBack({553, 2530, 96, 148}, 0.2f);
				//win.PushBack({646, 2566, 96, 112}, 0.2f);
				//win.PushBack({741, 2566, 96, 112}, 0.2f);
				//win.PushBack({1028, 2566, 96, 112}, 0.2f);
				win.PushBack({ 1840, 2256, 96, 209 }, 0.2f);
				win.PushBack({ 49, 2488, 96, 190 }, 0.2f);
				win.PushBack({ 158, 2498, 96, 180 }, 0.2f);
				win.PushBack({ 255, 2503, 96, 175 }, 0.2f);
				win.PushBack({ 356, 2513, 96, 165 }, 0.2f);
				win.PushBack({ 452, 2521, 96, 157 }, 0.2f);
				win.PushBack({ 553, 2530, 96, 148 }, 0.2f);
				win.PushBack({ 646, 2566, 96, 112 }, 0.2f);
				win.PushBack({ 741, 2566, 96, 112 }, 0.2f);
				win.PushBack({ 1028, 2566, 96, 112 }, 0.2f);
				win.loop = false;
			}
			 */
			//hEnd
		}
		//Wan-Fu
		{
			//idle
			// /*
			{
				idle.PushBack({ 28,26,118,126 }, 0.15f); //01
				idle.PushBack({ 150,26,118,126 }, 0.15f);
				idle.PushBack({ 272,26,118,126 }, 0.15f);
				idle.PushBack({ 394,26,118,126 }, 0.15f); //04
				idle.PushBack({ 514,26,118,126 }, 0.15f);
				idle.PushBack({ 635,26,118,126 }, 0.15f);
				idle.PushBack({ 754,40,118,112 }, 0.15f); //07
				idle.PushBack({ 873,40,118,112 }, 0.15f);
				idle.PushBack({ 991,40,118,112 }, 0.15f);
				idle.PushBack({ 394,26,118,126 }, 0.15f); //04
				idle.PushBack({ 514,26,118,126 }, 0.15f);
				idle.PushBack({ 635,26,118,126 }, 0.15f);
				idle.loop = true;
			}
			// forward
			{
				forward.PushBack({ 28,162,106,126 }, 0.3f);
				forward.PushBack({ 137,162,106,126 }, 0.3f);
				forward.PushBack({ 245,162,106,126 }, 0.3f);
				forward.PushBack({ 353,162,106,126 }, 0.3f);
				forward.PushBack({ 461,162,106,126 }, 0.3f);
				forward.PushBack({ 569,162,106,126 }, 0.3f);
				forward.PushBack({ 678,162,106,126 }, 0.3f);
				forward.PushBack({ 786,162,106,126 }, 0.3f);
				forward.PushBack({ 895,162,109,126 }, 0.3f);
				forward.PushBack({ 1008,162,109,126 }, 0.3f);
				forward.PushBack({ 1121,162,109,126 }, 0.3f);
				forward.PushBack({ 1232,162,112,126 }, 0.3f);
				forward.PushBack({ 1347,162,112,126 }, 0.3f);
				forward.PushBack({ 1462,162,112,126 }, 0.3f);
				forward.PushBack({ 1578,162,112,126 }, 0.3f);
				forward.PushBack({ 1693,162,113,126 }, 0.3f);
				forward.PushBack({ 1810,162,113,126 }, 0.3f);
				forward.PushBack({ 1926,162,114,126 }, 0.3f);
				forward.loop = true;
			}
			// backward
			{
				backward.PushBack({ 28,162,106,126 }, 0.3f);
				backward.PushBack({ 137,162,106,126 }, 0.3f);
				backward.PushBack({ 245,162,106,126 }, 0.3f);
				backward.PushBack({ 353,162,106,126 }, 0.3f);
				backward.PushBack({ 461,162,106,126 }, 0.3f);
				backward.PushBack({ 569,162,106,126 }, 0.3f);
				backward.PushBack({ 678,162,106,126 }, 0.3f);
				backward.PushBack({ 786,162,106,126 }, 0.3f);
				backward.PushBack({ 895,162,109,126 }, 0.3f);
				backward.PushBack({ 1008,162,109,126 }, 0.3f);
				backward.PushBack({ 1121,162,109,126 }, 0.3f);
				backward.PushBack({ 1232,162,112,126 }, 0.3f);
				backward.PushBack({ 1347,162,112,126 }, 0.3f);
				backward.PushBack({ 1462,162,112,126 }, 0.3f);
				backward.PushBack({ 1578,162,112,126 }, 0.3f);
				backward.PushBack({ 1693,162,113,126 }, 0.3f);
				backward.PushBack({ 1810,162,113,126 }, 0.3f);
				backward.PushBack({ 1926,162,114,126 }, 0.3f);
				backward.loop = true;
			}
			// jump neutral
			{
				jump_neutral.PushBack({ 28,305,106,139 }, 0.2f); //1
				jump_neutral.PushBack({ 138,305,106,139 }, 0.2f);
				jump_neutral.PushBack({ 248,305,106,139 }, 0.2f);
				jump_neutral.PushBack({ 357,296,106,103 }, 0.2f); //4
				jump_neutral.PushBack({ 467,296,106,103 }, 0.2f);
				jump_neutral.PushBack({ 577,296,106,103 }, 0.2f);
				jump_neutral.PushBack({ 685,296,107,83 }, 0.2f); //7
				jump_neutral.PushBack({ 795,296,106,103 }, 0.2f);
				jump_neutral.PushBack({ 905,296,106,103 }, 0.2f);
				jump_neutral.PushBack({ 357,296,106,103 }, 0.2f); //4
				jump_neutral.PushBack({ 467,296,106,103 }, 0.2f);
				jump_neutral.PushBack({ 577,296,106,103 }, 0.2f);
				jump_neutral.PushBack({ 28,305,106,139 }, 0.2f); //1
				jump_neutral.PushBack({ 138,305,106,139 }, 0.2f);
				jump_neutral.PushBack({ 248,305,106,139 }, 0.2f);
				jump_neutral.loop = false;
			}
			// jump forward
			{
				jump_forward.PushBack({ 28,305,106,139 }, 0.2f); //1
				jump_forward.PushBack({ 138,305,106,139 }, 0.2f);
				jump_forward.PushBack({ 248,305,106,139 }, 0.2f);
				jump_forward.PushBack({ 357,296,106,103 }, 0.2f); //4
				jump_forward.PushBack({ 467,296,106,103 }, 0.2f);
				jump_forward.PushBack({ 577,296,106,103 }, 0.2f);
				jump_forward.PushBack({ 685,296,107,83 }, 0.2f); //7
				jump_forward.PushBack({ 795,296,106,103 }, 0.2f);
				jump_forward.PushBack({ 905,296,106,103 }, 0.2f);
				jump_forward.PushBack({ 357,296,106,103 }, 0.2f); //4
				jump_forward.PushBack({ 467,296,106,103 }, 0.2f);
				jump_forward.PushBack({ 577,296,106,103 }, 0.2f);
				jump_forward.PushBack({ 28,305,106,139 }, 0.2f); //1
				jump_forward.PushBack({ 138,305,106,139 }, 0.2f);
				jump_forward.PushBack({ 248,305,106,139 }, 0.2f);
				jump_forward.loop = false;
			}
			// jump backward
			{
				jump_backward.PushBack({ 28,305,106,139 }, 0.2f); //1
				jump_backward.PushBack({ 138,305,106,139 }, 0.2f);
				jump_backward.PushBack({ 248,305,106,139 }, 0.2f);
				jump_backward.PushBack({ 357,296,106,103 }, 0.2f); //4
				jump_backward.PushBack({ 467,296,106,103 }, 0.2f);
				jump_backward.PushBack({ 577,296,106,103 }, 0.2f);
				jump_backward.PushBack({ 685,296,107,83 }, 0.2f); //7
				jump_backward.PushBack({ 795,296,106,103 }, 0.2f);
				jump_backward.PushBack({ 905,296,106,103 }, 0.2f);
				jump_backward.PushBack({ 357,296,106,103 }, 0.2f); //4
				jump_backward.PushBack({ 467,296,106,103 }, 0.2f);
				jump_backward.PushBack({ 577,296,106,103 }, 0.2f);
				jump_backward.PushBack({ 28,305,106,139 }, 0.2f); //1
				jump_backward.PushBack({ 138,305,106,139 }, 0.2f);
				jump_backward.PushBack({ 248,305,106,139 }, 0.2f);
				jump_backward.loop = false;
			}

			//kick
			{
				kick.PushBack({ 28,745,108,148 }, 0.5f);//1
				kick.PushBack({ 139,745,108,148 }, 0.5f);
				kick.PushBack({ 249,745,108,148 }, 0.5f);
				kick.PushBack({ 358,745,99,148 }, 0.5f);//4
				kick.PushBack({ 459,745,99,148 }, 0.5f);
				kick.PushBack({ 560,745,99,148 }, 0.5f);
				kick.PushBack({ 660,745,99,148 }, 0.5f);//7
				kick.PushBack({ 762,745,99,148 }, 0.5f);
				kick.PushBack({ 863,745,99,148 }, 0.5f);
				kick.PushBack({ 964,745,99,148 }, 0.5f);//10
				kick.PushBack({ 1067,745,99,148 }, 0.5f);
				kick.PushBack({ 1168,745,99,148 }, 0.5f);
				kick.PushBack({ 660,745,99,148 }, 0.5f);//7
				kick.PushBack({ 762,745,99,148 }, 0.5f);
				kick.PushBack({ 863,745,99,148 }, 0.5f);
				kick.PushBack({ 358,745,99,148 }, 0.5f);//4
				kick.PushBack({ 459,745,99,148 }, 0.5f);
				kick.PushBack({ 560,745,99,148 }, 0.5f);
				kick.PushBack({ 28,745,108,148 }, 0.5f);//1
				kick.PushBack({ 139,745,108,148 }, 0.5f);
				kick.PushBack({ 249,745,108,148 }, 0.5f);
				kick.loop = false;
			}

			//punch
			{
				punch.PushBack({ 27, 451, 87, 168 }, 0.5f);
				punch.PushBack({ 116, 451, 87, 168 }, 0.5f);
				punch.PushBack({ 207, 492, 134, 127 }, 0.5f);
				punch.PushBack({ 342, 492, 134, 127 }, 0.5f);
				punch.PushBack({ 477, 474, 134, 143 }, 0.5f);
				punch.PushBack({ 614, 474, 134, 143 }, 0.5f);
				punch.PushBack({ 751, 490, 132, 128 }, 0.5f);
				punch.PushBack({ 891, 490, 132, 128 }, 0.5f);
				punch.PushBack({ 1031, 530, 136, 89 }, 0.5f);
				punch.PushBack({ 1172, 530, 136, 89 }, 0.5f);
				punch.PushBack({ 1313, 542, 133, 75 }, 0.5f);
				punch.PushBack({ 1449, 542, 133, 75 }, 0.5f);
				punch.PushBack({ 1587, 542, 133, 75 }, 0.5f);
				punch.PushBack({ 1724, 542, 133, 75 }, 0.5f);
				punch.PushBack({ 1861, 542, 133, 75 }, 0.5f);
				punch.PushBack({ 27, 620, 103, 125 }, 0.5f);
				punch.PushBack({ 133, 620, 103, 125 }, 0.5f);
				punch.PushBack({ 237, 620, 103, 125 }, 0.5f);
				punch.PushBack({ 341, 620, 103, 125 }, 0.5f);
				punch.PushBack({ 447, 620, 103, 125 }, 0.5f);
				punch.loop = false;
			}

			//crouch down
			{
				crouch_down.PushBack({ 1355, 28, 107, 124 }, 0.5f);
				crouch_down.PushBack({ 1466, 28, 107, 124 }, 0.5f);
				crouch_down.PushBack({ 1578, 28, 107, 124 }, 0.5f);
				crouch_down.PushBack({ 1691, 58, 107, 93 }, 0.5f);
				crouch_down.PushBack({ 1803, 58, 107, 93 }, 0.5f);
				crouch_down.PushBack({ 1914, 58, 107, 93 }, 0.5f);
				crouch_down.loop = false;
			}

			//crouch up
			{
				crouch_up.PushBack({ 1355, 28, 107, 124 }, 0.5f);
				crouch_up.PushBack({ 1466, 28, 107, 124 }, 0.5f);
				crouch_up.PushBack({ 1578, 28, 107, 124 }, 0.5f);
				crouch_up.loop = false;
			}

			//crouch kick
			{
				crouch_kick.PushBack({ 1190, 332, 107, 112 }, 0.5f);
				crouch_kick.PushBack({ 1303, 332, 107, 112 }, 0.5f);
				crouch_kick.PushBack({ 1414, 340, 112, 104 }, 0.5f);
				crouch_kick.PushBack({ 1532, 334, 130, 110 }, 0.5f);
				crouch_kick.PushBack({ 1667, 334, 130, 110 }, 0.5f);
				crouch_kick.PushBack({ 1803, 339, 112, 105 }, 0.5f);
				crouch_kick.PushBack({ 1921, 339, 112, 105 }, 0.5f);
				crouch_kick.loop = false;
			}

			//crouch punch
			{
				crouch_punch.PushBack({ 28, 1082, 119, 128 }, 0.5f);
				crouch_punch.PushBack({ 146, 1082, 119, 128 }, 0.5f);
				crouch_punch.PushBack({ 264, 1075, 117, 135 }, 0.5f);
				crouch_punch.PushBack({ 381, 1075, 117, 135 }, 0.5f);
				crouch_punch.PushBack({ 497, 1075, 117, 135 }, 0.5f);
				crouch_punch.PushBack({ 614, 1044, 138, 167 }, 0.5f);
				crouch_punch.PushBack({ 752, 1047, 138, 164 }, 0.5f);
				crouch_punch.PushBack({ 891, 1047, 138, 164 }, 0.5f);
				crouch_punch.PushBack({ 1046, 1082, 127, 129 }, 0.5f);
				crouch_punch.PushBack({ 1203, 1123, 138, 88 }, 0.5f);
				crouch_punch.PushBack({ 1340, 1123, 138, 88 }, 0.5f);
				crouch_punch.PushBack({ 1480, 1084, 102, 126 }, 0.5f);
				crouch_punch.PushBack({ 1593, 1084, 102, 126 }, 0.5f);
				crouch_punch.PushBack({ 1701, 1084, 102, 126 }, 0.5f);
				crouch_punch.loop = false;

			}
			//en garde
			{
				en_garde.PushBack({ 28,901,119,126 }, 0.2f);
				en_garde.PushBack({ 152,901,119,126 }, 0.2f);
				en_garde.PushBack({ 275,901,119,126 }, 0.2f);
				en_garde.PushBack({ 399,901,119,126 }, 0.2f);
				en_garde.PushBack({ 526,901,119,126 }, 0.2f);
				en_garde.PushBack({ 654,901,119,126 }, 0.2f);
				en_garde.PushBack({ 778,901,119,126 }, 0.2f);
				en_garde.PushBack({ 903,901,119,126 }, 0.2f);
				en_garde.PushBack({ 1027,901,119,126 }, 0.2f);
				en_garde.loop = false;
			}

			//hit 
			{
				hit.PushBack({ 28,1227,127,156 }, 0.3f);//1
				hit.PushBack({ 162,1227,127,156 }, 0.3f);
				hit.PushBack({ 296,1227,127,156 }, 0.3f);
				hit.PushBack({ 429,1227,173,156 }, 0.3f);//4
				hit.PushBack({ 609,1227,173,156 }, 0.3f);
				hit.PushBack({ 788,1227,173,156 }, 0.3f);
				hit.PushBack({ 28,1227,127,156 }, 0.3f);//1
				hit.PushBack({ 162,1227,127,156 }, 0.3f);
				hit.PushBack({ 296,1227,127,156 }, 0.3f);
				hit.loop = false;
			}

			//special attack
			{

				specialattack.PushBack({ 34, 1395, 73, 170 }, 0.1f);//1
				specialattack.PushBack({ 160, 1395, 73, 170 }, 0.1f);
				specialattack.PushBack({ 272, 1395, 73, 170 }, 0.1f);
				specialattack.PushBack({ 380, 1395, 117, 92 }, 0.25f);//4
				specialattack.PushBack({ 527, 1395, 116, 85 }, 0.25f);
				specialattack.PushBack({ 674, 1395, 113, 78 }, 0.25f);
				specialattack.PushBack({ 791, 1395, 100, 55 }, 0.35f);//7
				specialattack.PushBack({ 913, 1395, 99, 52 }, 0.35f);
				specialattack.PushBack({ 1045, 1395, 96, 49 }, 0.35f);
				specialattack.PushBack({ 1165, 1395, 69, 45 }, 0.8f);//10
				specialattack.PushBack({ 1271, 1395, 69, 45 }, 0.8f);//11
				specialattack.PushBack({ 1379, 1395, 69, 45 }, 0.8f);
				specialattack.PushBack({ 1488, 1395, 63, 46 }, 0.8f);
				specialattack.PushBack({ 1583, 1395, 63, 47 }, 0.8f);
				specialattack.PushBack({ 1667, 1395, 63, 50 }, 0.8f);//15
				specialattack.PushBack({ 1757, 1395, 63, 52 }, 0.8f);//16
				specialattack.PushBack({ 1847, 1395, 63, 57 }, 0.7f);
				specialattack.PushBack({ 1930, 1395, 103, 55 }, 0.7f);
				specialattack.PushBack({ 29, 1574, 103, 58 }, 0.7f);//19
				specialattack.PushBack({ 168, 1574, 128, 62 }, 0.7f);
				specialattack.PushBack({ 310, 1574, 91, 68 }, 0.7f);
				specialattack.PushBack({ 429, 1574, 91, 73 }, 0.7f);//22
				specialattack.PushBack({ 548, 1574, 91, 79 }, 0.7f);
				specialattack.PushBack({ 679, 1574, 62, 94 }, 0.05f);//24
				specialattack.PushBack({ 795, 1574, 88, 121 }, 0.01f);//25
				specialattack.loop = false;

			}

			//win animation
			{
				win.PushBack({ 40, 1711, 110, 117 }, 0.1f);
				win.PushBack({ 181, 1711, 110, 117 }, 0.1f);
				win.PushBack({ 332, 1711, 110, 117 }, 0.1f);
				win.PushBack({ 479, 1711, 110, 118 }, 0.1f);
				win.PushBack({ 619, 1711, 110, 118 }, 0.1f);
				win.PushBack({ 759, 1711, 110, 118 }, 0.1f);
				win.PushBack({ 896, 1711, 110, 116 }, 0.1f);
				win.PushBack({ 1032, 1711, 110, 116 }, 0.1f);
				win.PushBack({ 1170, 1711, 110, 116 }, 0.1f);
				win.PushBack({ 1303, 1711, 110, 120 }, 0.1f);
				win.PushBack({ 1433, 1711, 110, 120 }, 0.1f);
				win.PushBack({ 1557, 1711, 110, 120 }, 0.1f);
				win.loop = true;
			}

			//jump_kick

			{
				jump_punch.PushBack({ 820, 635, 115, 112 }, 0.3f);//1
				jump_punch.PushBack({ 956, 635, 115, 112 }, 0.3f);
				jump_punch.PushBack({ 1089, 635, 115, 112 }, 0.3f);
				jump_punch.PushBack({ 1227, 619, 108, 136 }, 0.3f);
				jump_punch.PushBack({ 1255, 619, 108, 136 }, 0.3f);
				jump_punch.PushBack({ 1487, 619, 108, 136 }, 0.3f);
				jump_punch.PushBack({ 1619, 621, 125, 130 }, 0.3f);
				jump_punch.PushBack({ 1766, 619, 125, 130 }, 0.3f);
				jump_punch.PushBack({ 1914, 619, 125, 130 }, 0.3f);
				jump_punch.PushBack({ 1443, 764, 119, 130 }, 0.3f);
				jump_punch.PushBack({ 1586, 764, 119, 130 }, 0.3f);
				jump_punch.PushBack({ 1750, 764, 119, 130 }, 0.3f);
				jump_punch.loop = false;
			}

			//jump_punch
			{
				jump_kick.PushBack({ 30, 1831, 111, 104 }, 0.3f);
				jump_kick.PushBack({ 164, 1831, 111, 104 }, 0.3f);
				jump_kick.PushBack({ 313, 1831, 111, 104 }, 0.3f);
				jump_kick.PushBack({ 466, 1831, 132, 110 }, 0.3f);
				jump_kick.PushBack({ 625, 1831, 132, 110 }, 0.3f);
				jump_kick.PushBack({ 1271, 1831, 132, 110 }, 0.3f);
				jump_kick.PushBack({ 790, 1831, 133, 125 }, 0.3f);
				jump_kick.PushBack({ 949, 1831, 133, 125 }, 0.3f);
				jump_kick.PushBack({ 1112, 1831, 133, 125 }, 0.3f);
				jump_kick.loop = false;
			}

			//grab animation
			
			{
				grab.PushBack({ 31, 8, 133, 128}, 0.5f);
				grab.PushBack({ 164, 8, 133, 128}, 0.5f);
				grab.PushBack({ 298, 8, 133, 128}, 0.5f);
				grab.PushBack({ 432, 10, 135, 126}, 0.5f);
				grab.PushBack({ 568, 10, 135, 126}, 0.5f);
				grab.PushBack({ 705, 10, 135, 126}, 0.5f);
				grab.PushBack({ 840, 0, 172, 136}, 0.5f);
				grab.PushBack({ 1014, 0, 172, 136}, 0.5f);
				grab.PushBack({ 1187, 0, 172, 136}, 0.5f);
				grab.PushBack({ 1358, 30, 157, 106}, 0.5f);
				grab.PushBack({ 1515, 30, 157, 106}, 0.5f);
				grab.PushBack({ 1670, 30, 157, 106}, 0.5f);
				grab.PushBack({ 1805, 7, 81, 129}, 0.5f);//red
				grab.PushBack({ 1886, 7, 81, 129}, 0.5f);
				grab.PushBack({ 31, 135, 81, 129}, 0.5f);
				grab.PushBack({ 111, 135, 81, 129}, 0.5f);
				grab.PushBack({ 349, 155, 118, 87}, 0.5f);
				grab.PushBack({ 467, 155, 118, 87}, 0.5f);
				grab.PushBack({ 585, 155, 188, 87}, 0.5f);
				grab.PushBack({ 704, 144, 86, 120}, 0.5f);
				grab.PushBack({ 790, 144, 86, 120}, 0.5f);
				grab.PushBack({ 876, 144, 86, 120}, 0.5f);
				grab.PushBack({ 964, 164, 129, 100}, 0.5f);
				grab.PushBack({ 1093, 164, 129, 100}, 0.5f);
				grab.PushBack({ 1222, 164, 129, 100}, 0.5f);
				grab.PushBack({ 1351, 164, 107, 100}, 0.5f);
				grab.PushBack({ 1458, 164, 107, 100}, 0.5f);
				grab.PushBack({ 1566, 164, 107, 100}, 0.5f);
				grab.PushBack({ 1673, 182, 106, 82}, 0.5f);
				grab.PushBack({ 1779, 182, 106, 82}, 0.5f);
				grab.PushBack({ 1885, 182, 106, 82}, 0.5f);
				grab.PushBack({ 30, 264, 107, 103}, 0.5f);
				grab.PushBack({ 138, 264, 107, 103}, 0.5f);
				grab.PushBack({ 246, 264, 107, 103}, 0.5f);
				grab.PushBack({ 352, 264, 106, 139}, 0.5f);
				grab.loop = false;
			}
			
			//heavy punch
			{
				heavy_punch.PushBack({ 34, 1948, 105, 95 }, 0.5f);
				heavy_punch.PushBack({ 156, 1948, 105, 95 }, 0.5f);
				heavy_punch.PushBack({ 275, 1948, 105, 95 }, 0.5f);
				heavy_punch.PushBack({ 399, 1946, 92, 97 }, 0.5f);
				heavy_punch.PushBack({ 515, 1946, 92, 97 }, 0.5f);
				heavy_punch.PushBack({ 626, 1946, 92, 97 }, 0.5f);
				heavy_punch.PushBack({ 739, 1950, 107, 93 }, 0.5f);
				heavy_punch.PushBack({ 848, 1950, 107, 93 }, 0.5f);
				heavy_punch.PushBack({ 958, 1950, 107, 93 }, 0.5f);
				heavy_punch.PushBack({ 1068, 1951, 162, 92 }, 0.5f);
				heavy_punch.PushBack({ 1230, 1951, 162, 92 }, 0.5f);
				heavy_punch.PushBack({ 1392, 1951, 162, 92 }, 0.5f);
				heavy_punch.PushBack({ 1552, 1946, 162, 97 }, 0.5f);
				heavy_punch.PushBack({ 1714, 1946, 162, 97 }, 0.5f);
				heavy_punch.PushBack({ 1879, 1946, 162, 97 }, 0.5f);
				heavy_punch.PushBack({ 547, 1479, 162, 95 }, 0.5f);
				heavy_punch.PushBack({ 708, 1479, 162, 95 }, 0.5f);
				heavy_punch.PushBack({ 868, 1481, 162, 93 }, 0.5f);
				heavy_punch.PushBack({ 1029, 1481, 162, 93 }, 0.5f);
				heavy_punch.PushBack({ 1191, 1481, 162, 93 }, 0.5f);
				heavy_punch.PushBack({ 34, 1948, 105, 95 }, 0.5f);
				heavy_punch.PushBack({ 156, 1948, 105, 95 }, 0.5f);
				heavy_punch.PushBack({ 275, 1948, 105, 95 }, 0.5f);
				heavy_punch.loop = false;
			}
			//heavy kick
			{
				heavy_kick.PushBack({ 1198, 917, 107, 111 }, 0.5f);//1
				heavy_kick.PushBack({ 1305, 917, 107, 111 }, 0.5f);
				heavy_kick.PushBack({ 1412, 917, 107, 111 }, 0.5f);
				heavy_kick.PushBack({ 1536, 917, 119, 111 }, 0.5f);
				heavy_kick.PushBack({ 1664, 917, 119, 111 }, 0.5f);
				heavy_kick.PushBack({ 1798, 917, 119, 111 }, 0.5f);
				heavy_kick.PushBack({ 1932, 910, 114, 117 }, 0.5f);
				heavy_kick.PushBack({ 999, 1266, 114, 117 }, 0.5f);
				heavy_kick.PushBack({ 1113, 1266, 114, 117 }, 0.5f);
				heavy_kick.PushBack({ 1226, 1258, 114, 125 }, 0.5f);
				heavy_kick.PushBack({ 1341, 1258, 114, 125 }, 0.5f);
				heavy_kick.PushBack({ 1455, 1258, 114, 125 }, 0.5f);
				heavy_kick.PushBack({ 1536, 917, 119, 111 }, 0.5f);
				heavy_kick.PushBack({ 1664, 917, 119, 111 }, 0.5f);
				heavy_kick.PushBack({ 1798, 917, 119, 111 }, 0.5f);
				heavy_kick.PushBack({ 1305, 917, 107, 111 }, 0.5f);
				heavy_kick.PushBack({ 1412, 917, 107, 111 }, 0.5f);
				heavy_kick.loop = false;
			}
			//die
			{
				die.PushBack({ 28,1227,127,156 }, 0.3f);//1
				die.PushBack({ 162,1227,127,156 }, 0.3f);
				die.PushBack({ 296,1227,127,156 }, 0.3f);
				die.PushBack({ 429,1227,173,156 }, 0.3f);//4
				die.PushBack({ 609,1227,173,156 }, 0.3f);
				die.PushBack({ 788,1227,173,156 }, 0.3f);
				die.PushBack({ 28,1227,127,156 }, 0.3f);//1
				die.PushBack({ 162,1227,127,156 }, 0.3f);
				die.PushBack({ 296,1227,127,156 }, 0.3f);
				die.loop = false;
			}

			//dash forward
			{
				dash_forward.PushBack({ 45, 417, 116, 115}, 0.5f);
				dash_forward.PushBack({ 162, 417, 116, 115 }, 0.5f);
				dash_forward.PushBack({ 277, 417, 116, 115 }, 0.5f);
				dash_forward.PushBack({ 393, 404, 122, 129}, 0.5f);
				dash_forward.PushBack({ 515, 404, 122, 129}, 0.5f);
				dash_forward.PushBack({ 638, 404, 122, 129}, 0.5f);
				dash_forward.PushBack({ 761, 403, 117, 130}, 0.5f);
				dash_forward.PushBack({ 877, 403, 117, 130}, 0.5f);
				dash_forward.PushBack({ 393, 404, 122, 129}, 0.5f);
				dash_forward.PushBack({ 515, 404, 122, 129}, 0.5f);
				dash_forward.PushBack({ 638, 404, 122, 129}, 0.5f);
				dash_forward.PushBack({ 45, 417, 116, 115 }, 0.5f);
				dash_forward.PushBack({ 162, 417, 116, 115 }, 0.5f);
				dash_forward.PushBack({ 277, 417, 116, 115 }, 0.5f);
				dash_forward.loop = false;
			}


			//dash backward
			
			{
				dash_backward.PushBack({ 368, 579, 106, 156}, 0.5f);
				dash_backward.PushBack({ 368, 579, 106, 156 }, 0.5f);
				dash_backward.PushBack({ 368, 579, 106, 156 }, 0.5f);
				dash_backward.PushBack({ 46, 579, 107, 156 }, 0.5f);
				dash_backward.PushBack({ 154, 579, 107, 156 }, 0.5f);
				dash_backward.PushBack({ 261, 579, 107, 156 }, 0.5f);
				dash_backward.loop = false;
			}
			
		// */
		}
	}
}

ModulePlayer::~ModulePlayer() {}

// Load assets
bool ModulePlayer::Start()
{
	bool ret = true;
	LOG("Loading player 1\n");
	initial_position.x = position.x = shadow_x = 25;
	position.y = initial_position.y = 215;
	lposition = position;
	//player_textures = App->textures->Load("Assets/Sprites/Characters/Haohmaru/Haohmaru.png");
	spritesheet1 = App->textures->Load("Assets/Sprites/Characters/Wan-Fu/Wan-Fu.png");
	spritesheet2 = App->textures->Load("Assets/Sprites/Characters/Wan-Fu/Wan-Fu2.png");
	attack_fx = App->audio->LoadFX("Assets/Audio/Fx/Characters/common/light_attack.wav");
	kick_fx = App->audio->LoadFX("Assets/Audio/Fx/Characters/common/light_kick.wav");
	twister_fx = App->audio->LoadFX("Assets/Audio/Fx/Characters/Haohmaru/twister.wav");
	//hit_fx = App->audio->LoadFX("Assets/Audio/FX/Characters/Haohmaru/Hit_1.wav");
	hit_fx = App->audio->LoadFX("Assets/Audio/FX/Characters/Wan-Fu/Hit_1.wav");
	special_attack_fx = App->audio->LoadFX("Assets/Audio/Fx/Characters/Wan-Fu/special_attack.wav");
	App->ui->player1_point = 0;
	App->ui->player2_point = 0;
	state = IDLE;
	current_animation = &idle;
	inputs[0] = ' ';
	*first = inputs[0];
	*last = inputs[0];
	if (!collider_player_up)
		collider_player_up = App->collision->AddCollider({ position.x + 15, position.y - 85,30,40 }, COLLIDER_PLAYER, (Module*)App->player);
	if (!collider_player_down)
		collider_player_down = App->collision->AddCollider({ position.x + 10, position.y - 45,40,45 }, COLLIDER_PLAYER, (Module*)App->player);
	return ret;
}

bool ModulePlayer::CleanUp() {
	LOG("Unloading player\n");
	App->textures->Unload(player_textures);
	App->audio->UnLoadFx(attack_fx);
	App->audio->UnLoadFx(kick_fx);
	App->audio->UnLoadFx(hit_fx);
	App->audio->UnLoadFx(twister_fx);
	collider_player_up = nullptr;
	collider_player_mid = nullptr;
	collider_player_down = nullptr;
	collider_player_attack = nullptr;
	return true;
}

update_status ModulePlayer::PreUpdate()
{
	if (!App->is_paused) {
		if (controls) {
			player_input.pressing_A = App->input->keyboard[SDL_SCANCODE_A] == KEY_REPEAT || SDL_GameControllerGetAxis(App->input->controller_player_1, SDL_CONTROLLER_AXIS_LEFTX) <= -10000;
			player_input.pressing_D = App->input->keyboard[SDL_SCANCODE_D] == KEY_REPEAT || SDL_GameControllerGetAxis(App->input->controller_player_1, SDL_CONTROLLER_AXIS_LEFTX) >= 10000;
			player_input.pressing_S = App->input->keyboard[SDL_SCANCODE_S] == KEY_REPEAT || SDL_GameControllerGetAxis(App->input->controller_player_1, SDL_CONTROLLER_AXIS_LEFTY) >= 10000;
			player_input.pressing_W = App->input->keyboard[SDL_SCANCODE_W] == KEY_DOWN || SDL_GameControllerGetAxis(App->input->controller_player_1, SDL_CONTROLLER_AXIS_LEFTY) <= -10000;
			player_input.holding_V = App->input->keyboard[SDL_SCANCODE_V] == KEY_REPEAT || App->input->game_pad[SDL_CONTROLLER_BUTTON_A][GAME_PAD_1] == KEY_REPEAT;
			player_input.pressing_E = App->input->keyboard[SDL_SCANCODE_E] == KEY_DOWN;//App->input->game_pad[SDL_CONTROLLER_BUTTON_A][GAME_PAD_1] == KEY_REPEAT;
			player_input.pressing_C = App->input->keyboard[SDL_SCANCODE_C] == KEY_DOWN || App->input->game_pad[SDL_CONTROLLER_BUTTON_X][GAME_PAD_1] == KEY_DOWN;
			player_input.pressing_V = App->input->keyboard[SDL_SCANCODE_V] == KEY_DOWN || App->input->game_pad[SDL_CONTROLLER_BUTTON_A][GAME_PAD_1] == KEY_DOWN;
			player_input.pressing_B = App->input->keyboard[SDL_SCANCODE_B] == KEY_DOWN || App->input->game_pad[SDL_CONTROLLER_BUTTON_Y][GAME_PAD_1] == KEY_DOWN;
			player_input.pressing_N = App->input->keyboard[SDL_SCANCODE_N] == KEY_DOWN || App->input->game_pad[SDL_CONTROLLER_BUTTON_B][GAME_PAD_1] == KEY_DOWN;
			player_input.pressing_M = App->input->keyboard[SDL_SCANCODE_M] == KEY_DOWN; // || App->input->game_pad[SDL_CONTROLLER_BUTTON_X][GAME_PAD_1] == KEY_DOWN;
			player_input.pressing_Q = App->input->keyboard[SDL_SCANCODE_Q] == KEY_DOWN;
			player_input.pressing_F4 = App->input->keyboard[SDL_SCANCODE_F4] == KEY_DOWN;
			if (player_input.pressing_A && player_input.pressing_D) {
				player_input.pressing_A = false;
				player_input.pressing_D = false;
			}

		}	
		//states 
		{
			if (state == IDLE) {
				newInput(' ');
				if (player_input.pressing_A)
					state = BACKWARD;
				if (player_input.pressing_D)
					state = FORWARD;
				if (player_input.pressing_C) {
					state = PUNCH;
					checkSpecialAttack();
					hit_done++;
					App->audio->PlayFX(attack_fx);
				}
				if (player_input.pressing_V) {
					state = HEAVY_PUNCH;
					hit_done++;
					App->audio->PlayFX(attack_fx);
				}
				if (player_input.pressing_B) {
					state = KICK;
					hit_done++;
					App->audio->PlayFX(attack_fx);
				}
				if (player_input.pressing_N) {
					state = HEAVY_KICK;
					hit_done++;
					App->audio->PlayFX(kick_fx);
				}
				if (player_input.pressing_M) {
					//App->audio->PlayFX(twister_fx);
					App->audio->PlayFX(special_attack_fx);
					hit_done++;
					//state = TWISTER;
					state = SPECIAL_ATTACK;
					App->render->StartCameraShake(1200, 2);
					//App->render->StartSlowdown(750, 20);
				}
				if (player_input.pressing_W)
					state = JUMP_NEUTRAL;
				if (player_input.pressing_S)
					state = CROUCH_DOWN;
			}
			if (state == BACKWARD) {
				newInput('a');
				if (!player_input.pressing_A)
					state = IDLE;
				if (player_input.pressing_C) {
					state = PUNCH;
					hit_done++;
					App->audio->PlayFX(attack_fx);
				}
				if (player_input.pressing_V) {
					state = HEAVY_PUNCH;
					hit_done++;
					App->audio->PlayFX(attack_fx);
				}
				if (player_input.pressing_B) {
					state = KICK;
					hit_done++;
					App->audio->PlayFX(kick_fx);
				}
				if (player_input.pressing_N) {
					state = HEAVY_KICK;
					hit_done++;
					App->audio->PlayFX(kick_fx);
				}
				if (player_input.pressing_E)
				{
					state = GRAB;
				}
				if (player_input.pressing_M) {
					//App->audio->PlayFX(twister_fx);
					App->audio->PlayFX(special_attack_fx);
					hit_done++;
					//state = TWISTER;
					state = SPECIAL_ATTACK;
					App->render->StartCameraShake(1200, 2);
					//App->render->StartSlowdown(750, 20);
				}
				if (player_input.pressing_W)
					state = JUMP_BACKWARD;
			}
			if (state == FORWARD) {
				newInput('d');
				if (!player_input.pressing_D)
					state = IDLE;
				if (player_input.pressing_C) {
					state = PUNCH;
					hit_done++;
					App->audio->PlayFX(attack_fx);
				}
				if (player_input.pressing_V) {
					state = HEAVY_PUNCH;
					hit_done++;
					App->audio->PlayFX(attack_fx);
				}
				if (player_input.pressing_B) {
					state = KICK;
					hit_done++;
					App->audio->PlayFX(attack_fx);
				}
				if (player_input.pressing_N) {
					state = HEAVY_KICK;
					hit_done++;
					App->audio->PlayFX(kick_fx);
				}
				if (player_input.pressing_M) {
					//App->audio->PlayFX(twister_fx);
					App->audio->PlayFX(special_attack_fx);
					hit_done++;
					//state = TWISTER;
					state = SPECIAL_ATTACK;
					App->render->StartCameraShake(1200, 2);
					//App->render->StartSlowdown(750, 20);
				}
				if (player_input.pressing_E)
				{
					state = GRAB;
				}
				if (player_input.pressing_W)
					state = JUMP_FORWARD;
			}
			if (state == KICK) {
				newInput('b');
				if (current_animation->Finished()) {
					state = IDLE;
					kick.Reset();
					if (collider_player_mid != nullptr)
					{
						collider_player_mid->to_delete = true;
						collider_player_mid = nullptr;
					}
				}
			}
			if (state == PUNCH) {
				newInput('c');
				if (current_animation->Finished()) {
					state = IDLE;
					punch.Reset();
				}
			}
			if (state == JUMP_NEUTRAL)
			{
				newInput('w');
				if (player_input.pressing_C) {
					//hit_done++;
					state = JUMP_PUNCH;
					direction_x = 0;
					//App->audio->PlayFX(light_attack_fx);
				}
				if (player_input.pressing_B) {
					state = JUMP_KICK;
					//hit_done++;
				}
				if (player_input.pressing_A && mult == 1)
					state = JUMP_BACKWARD;
				if (player_input.pressing_D && mult == 1)
					state = JUMP_FORWARD;
					
				if (current_animation->Finished())
				{
					state = IDLE;
					jump_neutral.Reset();
				}
			}
			if (state == JUMP_FORWARD)
			{
				newInput('w');
				newInput('d');
				if (player_input.pressing_C) {
					hit_done++;
					state = JUMP_PUNCH;
					App->audio->PlayFX(attack_fx);
				}
				if (player_input.pressing_B) {
					state = JUMP_KICK;
					hit_done++;
				}
				if (current_animation->Finished())
				{
					state = IDLE;
					jump_forward.Reset();
				}
				direction_x = 1;
			}
			if (state == JUMP_BACKWARD)
			{
				newInput('w');
				newInput('a');
				if (player_input.pressing_C) {
					//hit_done++;
					state = JUMP_PUNCH;
					//App->audio->PlayFX(light_attack_fx);
				}
				if (player_input.pressing_B) {
					state = JUMP_KICK;
					//hit_done++;
				}
				if (current_animation->Finished())
				{
					state = IDLE;
					jump_backward.Reset();
				}
				direction_x = -1;
			}
			if (state == JUMP_PUNCH) {
				newInput('w');
				newInput('c');
				if ((current_animation->Finished())&&(position.y == initial_position.y))
				{
					state = IDLE;
					jump_punch.Reset();
				}
			}
			if (state == JUMP_KICK) {
				newInput('w');
				newInput('b');
				if ((current_animation->Finished())&&(position.y == initial_position.y))
				{
					state = IDLE;
					jump_kick.Reset();
				}
			}
			if (state == CROUCH_DOWN)
			{
				newInput('s');
				if (!player_input.pressing_S)
				{
					state = CROUCH_UP;
					crouch_down.Reset();
				}
				if (player_input.pressing_C) {
					hit_done++;
					state = CROUCH_PUNCH;
					App->audio->PlayFX(attack_fx);
				}
				if (player_input.pressing_B) {
					hit_done++;
					state = CROUCH_KICK;
					App->audio->PlayFX(kick_fx);
				}
			}
			if (state == CROUCH_UP)
			{
				if (current_animation->Finished()) {
					state = IDLE;
					crouch_up.Reset();
				}
			}
			if (state == TWISTER)
			{
				if (current_animation->Finished())
				{
					state = IDLE;
					twister.Reset();
					are_particles_created = false;
				}
			}
			if (state == CROUCH_KICK) {
				newInput('s');
				newInput('b');
				if (current_animation->Finished()) {
					state = IDLE;
					crouch_kick.Reset();
				}
			}
			if (state == CROUCH_PUNCH) {
				newInput('s');
				newInput('c');
				if (current_animation->Finished()) {
					state = IDLE;
					crouch_punch.Reset();
				}
			}
			if (state == HIT) {
				newInput(' ');
				if ((position.y < initial_position.y))
				{
					position.y++;
					if (flip == SDL_FLIP_HORIZONTAL)
					{
						position.x += speed/4;
					}
					else
					{
						position.x -= speed/4;
					}
				}
				else if (current_animation->Finished()){
					state = IDLE;
					hit.Reset();
				}
			}
			if (state == EN_GARDE)
			{
				newInput(' ');
				if (current_animation->Finished())
				{
					state = IDLE;
					en_garde.Reset();
				}
			}
			if (state == WIN)
			{
				newInput(' ');
				if (current_animation->Finished())
				{
					state = IDLE;
					win.Reset();
				}
			}
			if (state == SPECIAL_ATTACK)
			{
				newInput(' ');
				if (current_animation->Finished())
				{
					specialattack.Reset();
					are_particles_created = false;
					state = IDLE;
				}
			}
			if (state == HEAVY_PUNCH)
			{
				newInput('v');
				if (current_animation->Finished())
				{
					heavy_punch.Reset();
					state = IDLE;
				}
			}
			if (state == HEAVY_KICK)
			{
				newInput('n');
				if (current_animation->Finished())
				{
					heavy_kick.Reset();
					state = IDLE;
				}
			}
			if ((player_input.pressing_F4)) {
				god = !god;
			}
			if (state == GRAB)
			{
				if (current_animation->Finished()) {
					grab.Reset();
					state = IDLE;
				}
			}
			if ((!controls)&&(state != EN_GARDE))
			{
				state = IDLE;
			}
			if ((state != PUNCH) && (state != KICK) && (state != CROUCH_KICK) && (state != CROUCH_PUNCH) && (state != HEAVY_PUNCH) && (state != HEAVY_KICK)&&(state != JUMP_PUNCH) && (state != JUMP_KICK) && (collider_player_attack != nullptr))
			{
				collider_player_attack->to_delete = true;
				collider_player_attack = nullptr;
			}
			
		}
	}
	if (App->input->keyboard[SDL_SCANCODE_7] == KEY_DOWN) {
		state = States::IDLE;
		current_animation = &idle;
		App->player2->state2 = States2::IDLE2;
		App->player2->current_animation = &App->player2->idle2;
	}
	return UPDATE_CONTINUE;
}

update_status ModulePlayer::Update()
{
	lposition = position;
	shadow_x = position.x;

	if (!App->is_paused) {		

		switch (state)
		{
		case IDLE:
			current_animation = &idle;
			position.y = initial_position.y;
			//haohmaru
			/*
			if (flip == SDL_FLIP_HORIZONTAL) {
				collider_player_up->SetPos(position.x - 10, position.y - 80);
				collider_player_up->SetSize(30, 35);

				collider_player_down->SetPos(position.x - 15, position.y - 45);
				collider_player_down->SetSize(40, 45);
				shadow_x = position.x;
			}
			else {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x + 15, position.y - 80);
					collider_player_up->SetSize(30, 35);
				}
				if (collider_player_down != nullptr)
				{
					collider_player_down->SetPos(position.x + 10, position.y - 45);
					collider_player_down->SetSize(40, 45);
				}
			}*/
			//Wan-fu Idle
			if (flip == SDL_FLIP_HORIZONTAL) {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x - 22, position.y - 80);
					collider_player_up->SetSize(30, 35);
				}
				if (collider_player_down != nullptr)
				{
					collider_player_down->SetPos(position.x - 30, position.y - 45);
					collider_player_down->SetSize(40, 45);
				}

				shadow_x = position.x;
			}
			else {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x + 43, position.y - 80);
					collider_player_up->SetSize(38, 35);
				}
				if (collider_player_down != nullptr)
				{
					collider_player_down->SetPos(position.x + 30, position.y - 45);
					collider_player_down->SetSize(60, 45);
				}
				shadow_x = position.x + 23;
			}
			break;
		case FORWARD:
			current_animation = &forward;
			position.x += speed;
			//haohmaru
			/*
			if (flip == SDL_FLIP_HORIZONTAL) {
				collider_player_up->SetPos(position.x - 10, position.y - 85);
				collider_player_up->SetSize(30, 40);

				collider_player_down->SetPos(position.x - 15, position.y - 45);
				collider_player_down->SetSize(35, 45);
			}
			else {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x + 15, position.y - 85);
					collider_player_up->SetSize(30, 40);
				}
				if (collider_player_down != nullptr)
				{
					collider_player_down->SetPos(position.x + 10, position.y - 45);
					collider_player_down->SetSize(35, 45);
				}
			}*/
			//wan-fu Forward
			if (flip == SDL_FLIP_HORIZONTAL) {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x - 15, position.y - 85);
					collider_player_up->SetSize(30, 40);
				}
				if (collider_player_down != nullptr)
				{
					collider_player_down->SetPos(position.x - 25, position.y - 45);
					collider_player_down->SetSize(50, 45);
				}
			}
			else {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x + 30, position.y - 85);
					collider_player_up->SetSize(40, 40);
				}
				if (collider_player_down != nullptr)
				{
					collider_player_down->SetPos(position.x + 25, position.y - 45);
					collider_player_down->SetSize(55, 45);
				}
			}
			break;
		case BACKWARD:
			current_animation = &backward;
			shadow_x = position.x + 10;
			//haohmaru
			/*
			if (flip == SDL_FLIP_HORIZONTAL) {
				collider_player_up->SetPos(position.x - 25, position.y - 85);
				collider_player_up->SetSize(35, 40);
				collider_player_down->SetPos(position.x - 30, position.y - 45);
				collider_player_down->SetSize(50, 45);
				shadow_x = position.x;
			}
			else {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x + 25, position.y - 85);
					collider_player_up->SetSize(35, 40);
				}
				if (collider_player_down != nullptr) {
					collider_player_down->SetPos(position.x + 20, position.y - 45);
					collider_player_down->SetSize(50, 45);
				}
			}
			*/
			//wan-fu backward
			if (flip == SDL_FLIP_HORIZONTAL) {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x - 15, position.y - 85);
					collider_player_up->SetSize(35, 40);
				}
				if (collider_player_down != nullptr) {
					collider_player_down->SetPos(position.x - 20, position.y - 45);
					collider_player_down->SetSize(50, 45);
				}

				shadow_x = position.x;
			}
			else {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x + 25, position.y - 85);
					collider_player_up->SetSize(40, 40);
				}
				if (collider_player_down != nullptr) {
					collider_player_down->SetPos(position.x + 20, position.y - 45);
					collider_player_down->SetSize(50, 45);
				}
			}
			position.x -= speed;
			break;

		case CROUCH_DOWN:
			current_animation = &crouch_down;
			shadow_x = position.x + 16;
			//haohmaru
			/*
			if (flip == SDL_FLIP_HORIZONTAL) {
				collider_player_up->SetPos(position.x - 15, position.y - 80);
				collider_player_up->SetSize(35, 50);

				collider_player_down->SetPos(position.x - 20, position.y - 30);
				collider_player_down->SetSize(50, 30);

				collider_player_up->SetPos(position.x - 40, position.y - 65);
				collider_player_up->SetSize(35, 35);

				collider_player_down->SetPos(position.x - 40, position.y - 30);
				collider_player_down->SetSize(50, 30);
				shadow_x -= shadow_w / 3;
			}
			else {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x + 20, position.y - 65);
					collider_player_up->SetSize(35, 35);
				}
				if (collider_player_down != nullptr)
				{
					collider_player_down->SetPos(position.x + 10, position.y - 30);
					collider_player_down->SetSize(50, 30);
				}
				if (collider_player_up != nullptr && current_animation->SeeCurrentFrame() > 2 && current_animation->SeeCurrentFrame() < 6) {
					collider_player_up->SetPos(position.x + 45, position.y - 65);
					collider_player_up->SetSize(35, 35);

					collider_player_down->SetPos(position.x + 30, position.y - 30);
					collider_player_down->SetSize(50, 30);
				}
			}*/
			//wan-fu crouch down
			if (flip == SDL_FLIP_HORIZONTAL) {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x - 23, position.y - 80);
					collider_player_up->SetSize(35, 60);
				}
				if (collider_player_down != nullptr)
				{
					collider_player_down->SetPos(position.x - 40, position.y - 30);
					collider_player_down->SetSize(50, 30);
				}
				if (collider_player_up != nullptr && current_animation->SeeCurrentFrame() > 2 && current_animation->SeeCurrentFrame() < 6) {
					collider_player_up->SetPos(position.x - 35, position.y - 75);
					collider_player_up->SetSize(35, 35);

					collider_player_down->SetPos(position.x - 35, position.y - 30);
					collider_player_down->SetSize(50, 30);
				}

				shadow_x -= shadow_w / 3;
			}
			else {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x + 40, position.y - 85);
					collider_player_up->SetSize(35, 55);
				}
				if (collider_player_down != nullptr)
				{
					collider_player_down->SetPos(position.x + 20, position.y - 30);
					collider_player_down->SetSize(70, 30);
				}
				if (collider_player_up != nullptr && current_animation->SeeCurrentFrame() > 2 && current_animation->SeeCurrentFrame() < 6) {
					collider_player_up->SetPos(position.x + 35, position.y - 75);
					collider_player_up->SetSize(55, 45);

					collider_player_down->SetPos(position.x + 30, position.y - 30);
					collider_player_down->SetSize(60, 30);
				}
			}
			break;
		case CROUCH_UP:
			current_animation = &crouch_up;
			break;
		case CROUCH_KICK:
			current_animation = &crouch_kick;
			//haohmaru
			/*
			if (flip == SDL_FLIP_HORIZONTAL) {
				if (collider_player_up != nullptr) {
					collider_player_up->SetPos(position.x - 10, position.y - 55);
					collider_player_up->SetSize(40, 35);
				}

				if (collider_player_down != nullptr) {
					collider_player_down->SetPos(position.x - 30, position.y - 20);
					collider_player_down->SetSize(75, 25);
				}

				if (collider_player_attack == nullptr) {
					collider_player_attack = App->collision->AddCollider({ position.x - 50, position.y - 10,100,20 }, COLLIDER_PLAYER_1_ATTACK, (Module*)App->player);
					collider_player_attack->SetSize(85, 15);
				}
			}
			else {

				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x + 10, position.y - 55);
					collider_player_up->SetSize(40, 35);
				}
				if (collider_player_down != nullptr)
				{
					collider_player_down->SetPos(position.x + 5, position.y - 20);
					collider_player_down->SetSize(75, 25);
				}
				if (collider_player_attack == nullptr) {
					collider_player_attack = App->collision->AddCollider({ position.x + 15, position.y - 10,100,20 }, COLLIDER_PLAYER_1_ATTACK, (Module*)App->player);
					collider_player_attack->SetSize(85, 15);
				}
			}*/
			//wan-fu crouch kick
			if (flip == SDL_FLIP_HORIZONTAL) {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x - 10, position.y - 55);
					collider_player_up->SetSize(40, 35);
				}
				if (collider_player_down != nullptr)
				{
					collider_player_down->SetPos(position.x - 30, position.y - 20);
					collider_player_down->SetSize(75, 25);
				}
				if (collider_player_attack == nullptr) {
					collider_player_attack = App->collision->AddCollider({ position.x - 50, position.y - 10,100,20 }, COLLIDER_PLAYER_1_ATTACK, (Module*)App->player);
					collider_player_attack->SetSize(85, 15);
				}
			}
			else {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x + 30, position.y - 70);
					collider_player_up->SetSize(40, 50);
				}
				if (collider_player_down != nullptr)
				{
					collider_player_down->SetPos(position.x + 30, position.y - 20);
					collider_player_down->SetSize(40, 25);
				}
				if (collider_player_attack == nullptr) {
					collider_player_attack = App->collision->AddCollider({ position.x + 25, position.y - 10,100,20 }, COLLIDER_PLAYER_1_ATTACK, (Module*)App->player);
					collider_player_attack->SetSize(85, 15);
				}
				shadow_x = position.x + 30;
			}
			break;
		case CROUCH_PUNCH:
			current_animation = &crouch_punch;
			shadow_x = position.x + 20;
			if (flip == SDL_FLIP_HORIZONTAL) {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x - 20, position.y - 80);
					collider_player_up->SetSize(35, 50);
				}
				if (collider_player_down != nullptr)
				{
					collider_player_down->SetPos(position.x - 25, position.y - 30);
					collider_player_down->SetSize(70, 35);
				}
				if (collider_player_attack == nullptr)
				{
					collider_player_attack = App->collision->AddCollider({ position.x - 50, position.y - 50,80,40 }, COLLIDER_PLAYER_1_ATTACK, (Module*)App->player);
				}

				shadow_x -= shadow_w / 3;
			}
			else {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x + 35, position.y - 80);
					collider_player_up->SetSize(35, 50);
				}
				if (collider_player_down != nullptr)
				{
					collider_player_down->SetPos(position.x +5, position.y - 30);
					collider_player_down->SetSize(70, 35);
				}
				if (collider_player_attack == nullptr)
				{
					collider_player_attack = App->collision->AddCollider({ position.x + 55, position.y - 50,80,40 }, COLLIDER_PLAYER_1_ATTACK, (Module*)App->player);
				}
			}

			break;
		case JUMP_NEUTRAL:
			current_animation = &jump_neutral;

			position.y -= speed * 2 * mult;

			if (position.y <= 100) {
				mult = -1;
			}
			else if (position.y == initial_position.y)
			{
				mult = 1;
				jump_neutral.Reset();
				state = IDLE;
				App->render->StartCameraShake(400, 2);
			}
			else if (position.y > initial_position.y)
			{
				position.y = initial_position.y;
				mult = 1;
			}
			//haohmaru
			/*
			if (flip == SDL_FLIP_HORIZONTAL) {
				collider_player_up->SetPos(position.x, position.y - 90);
				collider_player_up->SetSize(35, 35);

				collider_player_down->SetPos(position.x - 12, position.y - 50);
				collider_player_down->SetSize(50, 30);
			}
			else {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x, position.y - 90);
					collider_player_up->SetSize(35, 35);
				}
				if (collider_player_down != nullptr)
				{
					collider_player_down->SetPos(position.x, position.y - 50);
					collider_player_down->SetSize(50, 30);
				}
			}
			*/
			//wan-fu jump neutral
			if (flip == SDL_FLIP_HORIZONTAL) {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x - 30, position.y - 100);
					collider_player_up->SetSize(35, 50);
				}
				if (collider_player_down != nullptr)
				{
					collider_player_down->SetPos(position.x - 40, position.y - 50);
					collider_player_down->SetSize(50, 30);
				}
			}
			else {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x+30, position.y - 90);
					collider_player_up->SetSize(45, 35);
				}
				if (collider_player_down != nullptr)
				{
					collider_player_down->SetPos(position.x+25, position.y - 50);
					collider_player_down->SetSize(55, 35);
				}
			}
			break;
		case JUMP_FORWARD:
			current_animation = &jump_forward;
			/*
			if (flip == SDL_FLIP_HORIZONTAL) {
				collider_player_up->SetPos(position.x - 20, position.y - 90);
				collider_player_up->SetSize(40, 50);

				collider_player_down->SetPos(position.x, position.y - 50);
				collider_player_down->SetSize(30, 30);

				if (current_animation->SeeCurrentFrame() > 5)
				{
					if (collider_player_up != nullptr)
					{
						collider_player_up->SetPos(position.x - 20, position.y - 45);
						collider_player_up->SetSize(45, 35);
					}
				}
			}
			else {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x + 15, position.y - 100);
					collider_player_up->SetSize(40, 50);
				}
				if (collider_player_down != nullptr)
				{
					collider_player_down->SetPos(position.x + 10, position.y - 60);
					collider_player_down->SetSize(30, 30);
				}
				if (current_animation->SeeCurrentFrame() > 4)
				{
					if (collider_player_up != nullptr)
					{
						collider_player_up->SetPos(position.x + 10, position.y - 55);
						collider_player_up->SetSize(45, 35);
					}
				}
			}
			*/
			//Wan-Fu Jump forward
			if (flip == SDL_FLIP_HORIZONTAL) {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x - 25, position.y - 90);
					collider_player_up->SetSize(40, 50);
				}
				if (collider_player_down != nullptr)
				{
					collider_player_down->SetPos(position.x - 35, position.y - 45);
					collider_player_down->SetSize(50, 35);
				}
				if (current_animation->SeeCurrentFrame() > 5)
				{
					if (collider_player_up != nullptr)
					{
						collider_player_up->SetPos(position.x - 40, position.y - 75);
						collider_player_up->SetSize(45, 35);

						collider_player_down->SetPos(position.x - 35, position.y - 45);
						collider_player_down->SetSize(50, 35);
					}
				}
			}
			else {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x + 35, position.y - 100);
					collider_player_up->SetSize(60, 50);
				}
				if (collider_player_down != nullptr)
				{
					collider_player_down->SetPos(position.x + 20, position.y - 50);
					collider_player_down->SetSize(50, 40);
				}
				if (current_animation->SeeCurrentFrame() > 1)
				{
					if (collider_player_up != nullptr)
					{
						collider_player_up->SetPos(position.x + 35, position.y - 90);
						collider_player_up->SetSize(45, 60);
					}
					if (collider_player_down != nullptr)
					{
						collider_player_down->SetPos(position.x + 20, position.y-45);
						collider_player_down->SetSize(75, 30);
					}
				}
			}
			position.y -= speed * 1.75 * mult;
			position.x += 1.25*speed;

			if (position.y <= 85) {
				mult = -1;
			}
			else if (position.y > initial_position.y)
			{
				position.y = initial_position.y;
				jump_forward.Reset();
				mult = 1;
				state = IDLE;
				App->render->StartCameraShake(400, 2);
			}
			else if (position.y > initial_position.y)
			{
				position.y = initial_position.y;
				mult = 1;
			}
			break;
		case JUMP_BACKWARD:
			current_animation = &jump_backward;

			position.y -= speed * 1.75 * mult;
			position.x -= 1.75*speed;

			if (position.y <= 85) {
				mult = -1;
			}
			else if (position.y == initial_position.y)
			{
				mult = 1;
				jump_backward.Reset();
				state = IDLE;
				App->render->StartCameraShake(400, 3);
			}
			else if (position.y > initial_position.y)
			{
				position.y = initial_position.y;
				jump_backward.Reset();
				state = IDLE;
				App->render->StartCameraShake(400, 3);
				mult = 1;
			}
			else if (position.y > initial_position.y)
			{
				position.y = initial_position.y;
				mult = 1;
			}
			//haohmaru
			/*
			if (flip != SDL_FLIP_HORIZONTAL)
			{
			if (collider_player_up != nullptr)
			{
			collider_player_up->SetPos(position.x, position.y - 90);
			collider_player_up->SetSize(35, 35);
			}
			if (collider_player_down != nullptr)
			{
			collider_player_down->SetPos(position.x, position.y - 50);
			collider_player_down->SetSize(40, 30);
			}
			if (current_animation->SeeCurrentFrame() > 4) {
			collider_player_up->SetPos(position.x + 20, position.y - 45);
			collider_player_up->SetSize(35, 35);
			}
			}
			else {
			if (collider_player_up != nullptr)
			{
			collider_player_up->SetPos(position.x, position.y - 90);
			collider_player_up->SetSize(35, 35);
			}
			if (collider_player_down != nullptr)
			{
			collider_player_down->SetPos(position.x, position.y - 50);
			collider_player_down->SetSize(40, 30);
			}
			if (current_animation->SeeCurrentFrame() > 4)
			{
			if (collider_player_up != nullptr)
			{
			collider_player_up->SetPos(position.x - 20, position.y - 45);
			collider_player_up->SetSize(35, 35);
			}
			}
			}
			*/
			//Wan-Fu Jump Backward
			if (flip == SDL_FLIP_HORIZONTAL) {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x - 25, position.y - 90);
					collider_player_up->SetSize(40, 50);
				}
				if (collider_player_down != nullptr)
				{
					collider_player_down->SetPos(position.x - 35, position.y - 45);
					collider_player_down->SetSize(50, 35);
				}
			}
			else {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x + 35, position.y - 100);
					collider_player_up->SetSize(60, 50);
				}
				if (collider_player_down != nullptr)
				{
					collider_player_down->SetPos(position.x + 20, position.y - 50);
					collider_player_down->SetSize(50, 40);
				}
				if (current_animation->SeeCurrentFrame() > 1)
				{
					if (collider_player_up != nullptr)
					{
						collider_player_up->SetPos(position.x + 35, position.y - 90);
						collider_player_up->SetSize(45, 60);
					}
					if (collider_player_down != nullptr)
					{
						collider_player_down->SetPos(position.x + 20, position.y - 45);
						collider_player_down->SetSize(75, 30);
					}
				}
			}
			shadow_x = position.x;
			break;
		case JUMP_PUNCH:
			current_animation = &jump_punch;
			//Wan-Fu Jump Punch
			if (flip == SDL_FLIP_HORIZONTAL) {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x - 20, position.y - 60);
					collider_player_up->SetSize(50, 47);
				}
				if (collider_player_up != nullptr)
				{
					collider_player_down->SetPos(position.x - 18, position.y - 10);
					collider_player_down->SetSize(70, 15);
				}
				if (collider_player_attack == nullptr)
				{
					collider_player_attack = App->collision->AddCollider({ position.x, position.y,78,40 }, COLLIDER_PLAYER_1_ATTACK, (Module*)App->player2);
					collider_player_attack->to_delete = false;
					collider_player_attack->SetPos(position.x - 60, position.y - 50);
					collider_player_attack->SetSize(67, 30);
				}
			}
			else {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x + 35, position.y - 60);
					collider_player_up->SetSize(50, 47);
				}
				if (collider_player_up != nullptr)
				{
					collider_player_down->SetPos(position.x + 5, position.y - 10);
					collider_player_down->SetSize(70, 15);
				}
				if (collider_player_attack == nullptr)
				{
					collider_player_attack = App->collision->AddCollider({ position.x, position.y,78,40 }, COLLIDER_PLAYER_1_ATTACK, (Module*)App->player2);
					collider_player_attack->to_delete = false;
					collider_player_attack->SetPos(position.x + 60, position.y - 50);
					collider_player_attack->SetSize(67, 30);
				}
			}

			position.y -= speed * 1.75 * mult;
			position.x += 1.25*speed*direction_x;

			if (position.y <= 100) {
				mult = -1;
			}
			else if (position.y > initial_position.y)
			{
				position.y = initial_position.y;
				jump_punch.Reset();
				mult = 1;
				state = IDLE;
				App->render->StartCameraShake(400, 2);
				direction_x = 0;
			}
			else if (position.y > initial_position.y)
			{
				position.y = initial_position.y;
				mult = 1;
			}
			shadow_x = position.x;
			break;
		case JUMP_KICK:
			current_animation = &jump_kick;
			//Wan-Fu Jump Kick
			if (flip == SDL_FLIP_HORIZONTAL) {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x - 25, position.y - 100);
					collider_player_up->SetSize(40, 75);
				}
				if (collider_player_down != nullptr)
				{
					collider_player_down->SetPos(position.x - 25, position.y - 100);
					collider_player_down->SetSize(1, 1);
				}
				if (collider_player_attack == nullptr)
				{
					collider_player_attack = App->collision->AddCollider({ position.x, position.y,80,40 }, COLLIDER_PLAYER_1_ATTACK, (Module*)App->player);
					collider_player_attack->SetPos(position.x - 50, position.y - 70);
					collider_player_attack->SetSize(45, 50);
				}
			}
			else {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x + 40, position.y - 100);
					collider_player_up->SetSize(40, 75);
				}
				if (collider_player_down != nullptr)
				{
					collider_player_down->SetPos(position.x + 40, position.y - 100);
					collider_player_down->SetSize(1, 1);
				}
				if (collider_player_attack == nullptr)
				{
					collider_player_attack = App->collision->AddCollider({ position.x, position.y,80,40 }, COLLIDER_PLAYER_1_ATTACK, (Module*)App->player);
					collider_player_attack->SetPos(position.x + 55, position.y - 70);
					collider_player_attack->SetSize(45, 50);
				}
			}

			position.y -= speed * 1.75 * mult;
			position.x += 1.25*speed*direction_x;

			if (position.y <= 100) {
				mult = -1;
			}
			else if (position.y > initial_position.y)
			{
				position.y = initial_position.y;
				jump_kick.Reset();
				mult = 1;
				state = IDLE;
				App->render->StartCameraShake(400, 2);
				direction_x = 0;
			}
			else if (position.y > initial_position.y)
			{
				position.y = initial_position.y;
				mult = 1;
			}
			shadow_x = position.x;
			break;
		case PUNCH:
			current_animation = &punch;
			//haohmaru
			/*
			if (flip == SDL_FLIP_HORIZONTAL) {
			if (collider_player_up != nullptr)
			{
			collider_player_up->SetPos(position.x - 20, position.y - 60);
			collider_player_up->SetSize(50, 47);
			}
			if (collider_player_up != nullptr)
			{
			collider_player_down->SetPos(position.x - 18, position.y - 10);
			collider_player_down->SetSize(70, 15);
			}
			if (collider_player_attack == nullptr)
			{
			collider_player_attack = App->collision->AddCollider({ position.x, position.y,78,40 }, COLLIDER_PLAYER_1_ATTACK, (Module*)App->player2);
			collider_player_attack->to_delete = false;
			collider_player_attack->SetPos(position.x - 60, position.y - 50);
			collider_player_attack->SetSize(67, 30);
			}
			}
			else {
			if (collider_player_up != nullptr)
			{
			collider_player_up->SetPos(position.x + 35, position.y - 60);
			collider_player_up->SetSize(50, 47);
			}
			if (collider_player_up != nullptr)
			{
			collider_player_down->SetPos(position.x + 5, position.y - 10);
			collider_player_down->SetSize(70, 15);
			}
			if (collider_player_attack == nullptr)
			{
			collider_player_attack = App->collision->AddCollider({ position.x, position.y,78,40 }, COLLIDER_PLAYER_1_ATTACK, (Module*)App->player2);
			collider_player_attack->to_delete = false;
			collider_player_attack->SetPos(position.x + 60, position.y - 50);
			collider_player_attack->SetSize(67, 30);
			}
			}
			*/
			//Wan-Fu Punch
			if (flip == SDL_FLIP_HORIZONTAL) {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x - 20, position.y - 60);
					collider_player_up->SetSize(50, 47);
				}
				if (collider_player_up != nullptr)
				{
					collider_player_down->SetPos(position.x - 18, position.y - 10);
					collider_player_down->SetSize(70, 15);
				}
				if (collider_player_attack == nullptr)
				{
					collider_player_attack = App->collision->AddCollider({ position.x, position.y,78,40 }, COLLIDER_PLAYER_1_ATTACK, (Module*)App->player2);
					collider_player_attack->to_delete = false;
					collider_player_attack->SetPos(position.x - 60, position.y - 50);
					collider_player_attack->SetSize(67, 30);
				}
			}
			else {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x + 35, position.y - 60);
					collider_player_up->SetSize(50, 47);
				}
				if (collider_player_up != nullptr)
				{
					collider_player_down->SetPos(position.x + 5, position.y - 10);
					collider_player_down->SetSize(70, 15);
				}
				if (collider_player_attack == nullptr)
				{
					collider_player_attack = App->collision->AddCollider({ position.x, position.y,78,40 }, COLLIDER_PLAYER_1_ATTACK, (Module*)App->player2);
					collider_player_attack->to_delete = false;
					collider_player_attack->SetPos(position.x + 60, position.y - 50);
					collider_player_attack->SetSize(67, 30);
				}
			}
			break;
		case DEATH:
			current_animation = &die;
			position.y = initial_position.y + 10;
			break;
		case KICK:
			current_animation = &kick;
			//Haohmaru
			/*
			if (flip == SDL_FLIP_HORIZONTAL) {
				collider_player_up->SetPos(position.x - 20, position.y - 70);
				collider_player_up->SetSize(50, 30);

				collider_player_down->SetPos(position.x, position.y - 80);
				collider_player_down->SetSize(25, 85);

				if (collider_player_attack == nullptr)
				{
					collider_player_attack = App->collision->AddCollider({ position.x - 43, position.y - 35,80,40 }, COLLIDER_PLAYER_1_ATTACK, (Module*)App->player2);
					collider_player_attack->SetSize(56, 30);
				}
			}
			else {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x + 10, position.y - 70);
					collider_player_up->SetSize(50, 30);
				}
				if (collider_player_down != nullptr)
				{
					collider_player_down->SetPos(position.x + 20, position.y - 80);
					collider_player_down->SetSize(25, 85);
				}
				if (collider_player_attack == nullptr)
				{
					collider_player_attack = App->collision->AddCollider({ position.x, position.y,80,40 }, COLLIDER_PLAYER_1_ATTACK, (Module*)App->player);
					collider_player_attack->SetPos(position.x + 30, position.y - 35);
					collider_player_attack->SetSize(56, 30);
				}
			}
			*/
			//Wan-Fu Kick
			if (flip == SDL_FLIP_HORIZONTAL) {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x - 25, position.y - 100);
					collider_player_up->SetSize(40, 75);
				}
				if (collider_player_down != nullptr)
				{
					collider_player_down->SetPos(position.x - 25, position.y - 100);
					collider_player_down->SetSize(1, 1);
				}
				if (collider_player_attack == nullptr)
				{
					collider_player_attack = App->collision->AddCollider({ position.x, position.y,80,40 }, COLLIDER_PLAYER_1_ATTACK, (Module*)App->player2);
					collider_player_attack->SetPos(position.x - 50, position.y - 70);
					collider_player_attack->SetSize(45, 50);
				}
			}
			else {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x + 40, position.y - 100);
					collider_player_up->SetSize(40, 75);
				}
				if (collider_player_down != nullptr)
				{
					collider_player_down->SetPos(position.x + 40, position.y - 100);
					collider_player_down->SetSize(1, 1);
				}
				if (collider_player_attack == nullptr)
				{
					collider_player_attack = App->collision->AddCollider({ position.x, position.y,80,40 }, COLLIDER_PLAYER_1_ATTACK, (Module*)App->player2);
					collider_player_attack->SetPos(position.x + 55, position.y - 70);
					collider_player_attack->SetSize(45, 50);
				}
			}
			break;
		case SPECIAL_ATTACK:
			//current_animation = &twister;
			current_animation = &specialattack;
			//haohmaru
			/*
			if (flip == SDL_FLIP_HORIZONTAL) {
			if (collider_player_up != nullptr)
			{
			collider_player_up->SetPos(position.x - 20, position.y - 75);
			collider_player_up->SetSize(40, 45);
			}
			if (collider_player_down != nullptr)
			{
			collider_player_down->SetPos(position.x - 35, position.y - 35);
			collider_player_down->SetSize(60, 40);
			}
			if (current_animation->SeeCurrentFrame() == 10 && !is_tornado_created) {
			Particle* p = App->particles->AddParticle(App->particles->tornado, position.x + 50, position.y - 205, COLLIDER_PLAYER_PARTICLES);
			is_tornado_created = true;
			p->speed = { -2,0 };
			}
			}
			else {
			if (collider_player_up != nullptr)
			{
			collider_player_up->SetPos(position.x + 15, position.y - 75);
			collider_player_up->SetSize(40, 45);
			}
			if (collider_player_down != nullptr)
			{
			collider_player_down->SetPos(position.x + 10, position.y - 35);
			collider_player_down->SetSize(60, 40);
			}
			if (current_animation->SeeCurrentFrame() == 10 && !is_tornado_created) {
			App->particles->AddParticle(App->particles->tornado, position.x + 50, position.y - 205, COLLIDER_PLAYER_PARTICLES);
			is_tornado_created = true;
			}
			}
			*/
			//Wan-Fu Special Attack
			if (flip == SDL_FLIP_HORIZONTAL) {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x - 23, position.y - 90);
					collider_player_up->SetSize(40, 45);
				}
				if (collider_player_down != nullptr)
				{
					collider_player_down->SetPos(position.x - 28, position.y - 45);
					collider_player_down->SetSize(60, 30);
				}
				if (current_animation->SeeCurrentFrame() == 14 && !are_particles_created) {
					App->particles->AddParticle(App->particles->fire_sword, position.x - 50, position.y, COLLIDER_PLAYER_PARTICLES);
					are_particles_created = true;
				}
				position.x += 1 * speed;
			}
			else {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x + 15, position.y - 90);
					collider_player_up->SetSize(45, 45);
				}
				if (collider_player_down != nullptr)
				{
					collider_player_down->SetPos(position.x+5, position.y - 50);
					collider_player_down->SetSize(60, 30);
				}
				if (current_animation->SeeCurrentFrame() == 14 && !are_particles_created) {
					App->particles->AddParticle(App->particles->fire_sword, position.x + 50, position.y, COLLIDER_PLAYER_PARTICLES);
					are_particles_created = true;
				}
				position.x -= 1 * speed;
			}
			position.y -= speed * 2 * mult;

			if (position.y <= 30) {
				mult = -1;
			}
			else if (position.y == initial_position.y)
			{
				mult = 1;
				specialattack.Reset();
				state = IDLE;
				are_particles_created = false;
			}
			else if (position.y > initial_position.y)
			{
				position.y = initial_position.y;
				specialattack.Reset();
				state = IDLE;
				are_particles_created = false;
				mult = 1;
			}
			else if (position.y > initial_position.y)
			{
				position.y = initial_position.y;
				mult = 1;
			}
			break;
		case WIN:
			current_animation = &win;
			break;
		case HIT:
			current_animation = &hit;
			shadow_x = position.x;
			//haohmaru
			/*
			if (flip == SDL_FLIP_HORIZONTAL) {

			}
			else {
			if (collider_player_up != nullptr)
			{
			collider_player_up->SetPos(position.x + 15, position.y - 85);
			}
			if (collider_player_down != nullptr)
			{
			collider_player_down->SetPos(position.x + 10, position.y - 45);
			}
			}
			break;
			*/
			//Wan-Fu Hit
			if (flip == SDL_FLIP_HORIZONTAL) {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x - 15, position.y - 85);
				}
				if (collider_player_down != nullptr)
				{
					collider_player_down->SetPos(position.x - 30, position.y - 45);
				}
			}
			else {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x + 15, position.y - 85);
				}
				if (collider_player_down != nullptr)
				{
					collider_player_down->SetPos(position.x + 10, position.y - 45);
				}
			}
			break;
		case EN_GARDE:
			current_animation = &en_garde;
			//Wan-Fu En garde
			if (flip == SDL_FLIP_HORIZONTAL) {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x - 22, position.y - 80);
					collider_player_up->SetSize(30, 35);
				}
				if (collider_player_down != nullptr)
				{
					collider_player_down->SetPos(position.x - 30, position.y - 45);
					collider_player_down->SetSize(40, 45);
				}

				shadow_x = position.x;
			}
			else {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x + 43, position.y - 80);
					collider_player_up->SetSize(38, 35);
				}
				if (collider_player_down != nullptr)
				{
					collider_player_down->SetPos(position.x + 30, position.y - 45);
					collider_player_down->SetSize(60, 45);
				}
				shadow_x = position.x + 23;
			}
			break;
		case HEAVY_PUNCH:
			current_animation = &heavy_punch;
			//Wan-Fu Heavy Punch
			if (flip == SDL_FLIP_HORIZONTAL) {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x - 15, position.y - 85);
					collider_player_up->SetSize(45, 45);
				}
				if (collider_player_down != nullptr)
				{
					collider_player_down->SetPos(position.x - 25, position.y - 50);
					collider_player_down->SetSize(60, 50);
				}
				if (collider_player_attack == nullptr)
				{
					collider_player_attack = App->collision->AddCollider({ position.x, position.y,78,40 }, COLLIDER_PLAYER_1_ATTACK, (Module*)App->player2);
					collider_player_attack->to_delete = false;
					collider_player_attack->SetPos(position.x - 45, position.y - 50);
					collider_player_attack->SetSize(70, 30);
				}
				if (current_animation->SeeCurrentFrame() > 7)
				{
					if (collider_player_up != nullptr)
					{
						collider_player_up->SetPos(position.x - 13, position.y - 75);
						collider_player_up->SetSize(45, 45);
					}
					if (collider_player_down != nullptr)
					{
						collider_player_down->SetPos(position.x - 12, position.y - 35);
						collider_player_down->SetSize(60, 35);
					}
					if (collider_player_attack != nullptr)
					{
						collider_player_attack->SetPos(position.x - 80, position.y - 55);
						collider_player_attack->SetSize(65, 30);
					}
				}
			}
			else {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x + 20, position.y - 85);
					collider_player_up->SetSize(45, 45);
				}
				if (collider_player_down != nullptr)
				{
					collider_player_down->SetPos(position.x + 15, position.y - 50);
					collider_player_down->SetSize(60, 50);
				}
				if (collider_player_attack == nullptr)
				{
					collider_player_attack = App->collision->AddCollider({ position.x, position.y,78,40 }, COLLIDER_PLAYER_1_ATTACK, (Module*)App->player2);
					collider_player_attack->to_delete = false;
					collider_player_attack->SetPos(position.x + 35, position.y - 50);
					collider_player_attack->SetSize(70, 30);
				}
				if (current_animation->SeeCurrentFrame() > 7)
				{
					if (collider_player_up != nullptr)
					{
						collider_player_up->SetPos(position.x + 50, position.y - 75);
						collider_player_up->SetSize(45, 45);
					}
					if (collider_player_down != nullptr)
					{
						collider_player_down->SetPos(position.x + 34, position.y - 35);
						collider_player_down->SetSize(60, 35);
					}
					if (collider_player_attack != nullptr)
					{
						collider_player_attack->SetPos(position.x + 96, position.y - 55);
						collider_player_attack->SetSize(65, 30);
					}
				}
			}
			shadow_x = position.x;
			break;
		case HEAVY_KICK:
			current_animation = &heavy_kick;
			//Wan-Fu Heavy Kick
			if (flip == SDL_FLIP_HORIZONTAL) {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x - 15, position.y - 95);
					collider_player_up->SetSize(35, 50);
				}
				if (collider_player_down != nullptr)
				{
					collider_player_down->SetPos(position.x - 15, position.y - 45);
					collider_player_down->SetSize(35, 45);
				}
				if (collider_player_attack == nullptr)
				{
					collider_player_attack = App->collision->AddCollider({ position.x, position.y,80,40 }, COLLIDER_PLAYER_1_ATTACK, (Module*)App->player2);
					collider_player_attack->SetPos(position.x - 60, position.y - 78);
					collider_player_attack->SetSize(55, 35);
				}
			}
			else {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x + 35, position.y - 95);
					collider_player_up->SetSize(35, 50);
				}
				if (collider_player_down != nullptr)
				{
					collider_player_down->SetPos(position.x + 35, position.y - 45);
					collider_player_down->SetSize(35, 45);
				}
				if (collider_player_attack == nullptr)
				{
					collider_player_attack = App->collision->AddCollider({ position.x, position.y,80,40 }, COLLIDER_PLAYER_1_ATTACK, (Module*)App->player2);
					collider_player_attack->SetPos(position.x + 63, position.y - 78);
					collider_player_attack->SetSize(55, 35);
				}
			}
			shadow_x = position.x;
			break;
		case JUMP_HEAVY_PUNCH:
			current_animation = &heavy_kick;
			//Wan-Fu Jump Heavy Punch
			if (flip == SDL_FLIP_HORIZONTAL) {


			}
			else {


			}
			shadow_x = position.x;
			break;
		case GRAB:
			current_animation = &grab;
			break;
		default:
			LOG("No state found :(");
			break;
		}
	}
	if ((position.y < initial_position.y) && ((state != JUMP_BACKWARD) && (state != JUMP_NEUTRAL) && (state != JUMP_FORWARD) && (state != HIT) && (state != SPECIAL_ATTACK)&&(state != JUMP_PUNCH)&&(state != JUMP_KICK)&&(state != GRAB)))
	{
		state = JUMP_NEUTRAL;
	}
	//Draw everything
	SDL_Rect r = current_animation->GetCurrentFrame();
	//haohmaru shadow
	// SDL_Rect shadow = { 1348, 2627, 70, 17 };
	//wan-fu shadow
	SDL_Rect shadow = { 1181,138,91,17 };
	SDL_RendererFlip lflip;
	lflip = flip;
	if (state == GRAB)
	{
		player_textures = spritesheet2;
	}
	else
	{
		player_textures = spritesheet1;
	}
	if (position.x < App->player2->position.x+App->player2->current_animation->GetCurrentFrame().w/2) {
		flip = SDL_FLIP_NONE;
	}
	else {
		flip = SDL_FLIP_HORIZONTAL;
	}
	if (flip != lflip)
	{
		if (flip == SDL_FLIP_NONE)
		{
			position.x -= current_animation->GetCurrentFrame().w / 2;
		}
		else
		{
			position.x += current_animation->GetCurrentFrame().w / 2;
		}
	}
	if (flip == SDL_FLIP_HORIZONTAL) {
		if (shadow_blit) {
			//shadow
			App->render->Blit(player_textures, shadow_x - shadow.w / 2, initial_position.y - 10, &shadow, flip);
			shadow_blit = false;
		}
		else {
			shadow_blit = true;
		}
		//player
		App->render->Blit(player_textures, position.x - current_animation->GetCurrentRect().w / 2, position.y - r.h, &r, flip);
	}
	else {
		if (shadow_blit) {
			//shadow
			App->render->Blit(player_textures, shadow_x, initial_position.y - 10, &shadow, flip);
			shadow_blit = false;
		}
		else {
			shadow_blit = true;
		}
		//player
		App->render->Blit(player_textures, position.x, position.y - r.h, &r, flip);

	}

	return UPDATE_CONTINUE;
}

void ModulePlayer::OnCollision(Collider* c1, Collider* c2) {

	if ((state != DEATH) && (!App->is_paused)) {
		switch (c2->type)
		{
		case COLLIDER_WALL_LEFT:
			if (!player_input.pressing_D && state != DEATH && state != WIN)
				position.x += speed;

			break;
		case COLLIDER_WALL_RIGHT:
			if (!player_input.pressing_A && state != DEATH && state != WIN)
				position.x -= speed;
			break;
		case COLLIDER_PLAYER_2:
			if (((state != KICK) && (state != PUNCH) && (state != CROUCH_KICK) && (state != CROUCH_PUNCH)) && (state != TWISTER) && (state != DEATH) && (state != WIN) && (state != HEAVY_PUNCH) && (state != HEAVY_KICK)&&(state != GRAB))
			{
				//if (App->player2->position.y == position.y)
				//{
					if (App->player2->position.x > position.x)
					{
						position.x = lposition.x - speed;
					}
					else
					{
						position.x = lposition.x + speed;
					}
				}
			//}
			break;
		case COLLIDER_PLAYER_2_ATTACK:
			if (!App->player2->collider_player_2_attack->to_delete && !god) {
				App->player2->hit_percent++;
				App->audio->PlayFX(hit_fx);
				App->judge->state_j = HIT2_J;
				life -= 10;
				state = HIT;
				App->player2->collider_player_2_attack->to_delete = true;
				if ((position.x < App->player2->position.x) && (position.x > App->render->left->rect.x + 60))
				{
					position.x -= 10;
				}
				else if ((position.x > App->player->position.x) && (position.x > App->render->right->rect.x))
				{
					position.x += 10;
				}
				switch (App->player2->state2)
				{
				case States2::KICK2:
					App->ui->player2_point += 50;
					break;
				case States2::PUNCH2:
					App->ui->player2_point += 50;
					break;
				case States2::CROUCH_PUNCH2:
					App->ui->player2_point += 200;
					break;
				case States2::CROUCH_KICK2:
					App->ui->player2_point += 200;
					break;
				case States2::TWISTER2:
					App->ui->player2_point += 400;
				case States2::JUMP_PUNCH2:
					App->ui->player2_point += 50;
					break;
				case States2::JUMP_KICK2:
					App->ui->player2_point += 50;
					break;
				default:
					break;
				}
			}
			App->render->StartCameraShake(400, 2);
			App->render->StartSlowdown(800, 30);
			break;
		case COLLIDER_PLAYER_2_PARTICLES:
			App->audio->PlayFX(hit_fx);
			App->judge->state_j = HIT2_J;
			life -= 20;
			state = HIT;
			position.x -= 5;
			App->render->StartCameraShake(400, 2);
			App->render->StartSlowdown(800, 30);
			break;
		default:
			break;
		}
	}
}

void ModulePlayer::BlockControls(bool block)
{
	controls = !block;
}

void ModulePlayer::PlayerCollidersCleanUp() {
	if (collider_player_up != nullptr)
	{
		collider_player_up->to_delete = true;
	}
	if (collider_player_mid != nullptr)
	{
		collider_player_mid->to_delete = true;
	}
	if (collider_player_down != nullptr)
	{
		collider_player_down->to_delete = true;
	}
}

bool ModulePlayer::checkSpecialAttack() {

	//Input button combination for special attack	
	int i = 0;
	int j = 0;
	int done = 0; //If done = 3. Special attack = true 
	
	while (i < 100) {
		switch (done) {
		case 0:
			if (inputs[j] == 'c')//punch
				done++;				
			break;
		case 1:
			if (inputs[j] == 'd')//forward
				done++;				
			break;
		case 2:
			if (inputs[j] == 'd' || 's')//down and forward
				done++;
			break;
		case 3:
			if (inputs[j] == 's') //down
				state = SPECIAL_ATTACK;
			return true;			
		default:
			//Special attack is false
			return false;
		}			

		if (j >0)
			j--;
		else
			j = 99;
		i++;
	}
	
	return false;
}

void ModulePlayer::newInput(char newInput) {
	inputs[*last] = newInput; //We add the newInput to the last inputs array

	if (*last < 99) //We change last pointer's position 
		(*last)++;	
	else
		*last = 0;
	
	//We change first pointer's position 
	if (*first == *last && *first < 99)
		(*first)++;
	else if (*first == *last && *first >= 99)
		* first = 0;
}