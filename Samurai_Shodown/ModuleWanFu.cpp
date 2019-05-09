#include "ModuleWanFu.h"
#include "ModuleTextures.h"

ModuleWanFu::ModuleWanFu() {
	//animations
	{
		{
			//idle animation
			{
				idle2.PushBack({ 16,22,71,109 }, 0.3f);
				idle2.PushBack({ 92,22,72,109 }, 0.3f);
				idle2.PushBack({ 168,22,71,109 }, 0.3f);
				idle2.PushBack({ 245,20,72,111 }, 0.3f);
				idle2.PushBack({ 322,18,72,113 }, 0.3f);
				idle2.PushBack({ 399,19,72,112 }, 0.3f);
				idle2.PushBack({ 476,19,74,112 }, 0.3f);
				idle2.PushBack({ 554,19,74,112 }, 0.3f);
				idle2.PushBack({ 630,19,73,112 }, 0.3f);
				idle2.PushBack({ 245,20,72,111 }, 0.3f);
				idle2.PushBack({ 322,18,72,113 }, 0.3f);
				idle2.PushBack({ 399,19,72,112 }, 0.3f);
			}

			//forward animation
			{
				forward2.PushBack({ 15,496,70,112 }, 0.4f);
				forward2.PushBack({ 89,496,70,112 }, 0.4f);
				forward2.PushBack({ 163,499,76,109 }, 0.4f);
				forward2.PushBack({ 243,499,76,109 }, 0.4f);
				forward2.PushBack({ 322,499,76,109 }, 0.4f);
				forward2.PushBack({ 402,496,69,112 }, 0.4f);
				forward2.PushBack({ 475,496,69,112 }, 0.4f);
				forward2.PushBack({ 548,496,69,112 }, 0.4f);
				forward2.PushBack({ 621,492,59,116 }, 0.4f);
				forward2.PushBack({ 684,492,59,116 }, 0.4f);
				forward2.PushBack({ 747,492,59,116 }, 0.4f);
				forward2.PushBack({ 810,492,57,116 }, 0.4f);
				forward2.PushBack({ 871,490,57,118 }, 0.4f);
				forward2.PushBack({ 933,490,56,118 }, 0.4f);
				forward2.PushBack({ 994,490,61,118 }, 0.4f);
				forward2.PushBack({ 1060,492,61,116 }, 0.4f);
				forward2.PushBack({ 1126,492,61,116 }, 0.4f);
			}

			//backward animation
			{
				backward2.PushBack({ 624,608,82,121 }, 0.4f);//9
				backward2.PushBack({ 711,608,82,121 }, 0.4f);//10
				backward2.PushBack({ 798,608,82,121 }, 0.4f);//11
				backward2.PushBack({ 884,608,82,121 }, 0.4f);//12
				backward2.PushBack({ 15,614,74,114 }, 0.4f); //1
				backward2.PushBack({ 94,614,74,114 }, 0.4f); //2
				backward2.PushBack({ 173,614,74,114 }, 0.4f); //3 
				backward2.PushBack({ 264,610,68,118 }, 0.4f); //4
				backward2.PushBack({ 337,610,68,118 }, 0.4f); //5
				backward2.PushBack({ 410,612,68,117 }, 0.4f); //6
				backward2.PushBack({ 482,609,67,121 }, 0.4f);//7
				backward2.PushBack({ 553,608,67,121 }, 0.4f);//8
				backward2.PushBack({ 971,608,69,122 }, 0.4f);//13
				backward2.PushBack({ 1045,608,69,121 }, 0.4f);//14
				backward2.PushBack({ 1119,608,69,120 }, 0.4f);//15
				backward2.PushBack({ 1193,614,74,114 }, 0.4f);//16
				backward2.PushBack({ 1272,614,74,114 }, 0.4f);//17
				backward2.PushBack({ 1351,614,74,114 }, 0.4f);//18
			}

			//jump animation
			{
				jump_neutral2.PushBack({ 15, 371, 60, 112 }, 0.2f); //1
				jump_neutral2.PushBack({ 80, 371, 60, 112 }, 0.2f); //2
				jump_neutral2.PushBack({ 145, 371, 60, 112 }, 0.2f); //3
				jump_neutral2.PushBack({ 209, 371, 75, 92 }, 0.2f);
				jump_neutral2.PushBack({ 288, 371, 75, 92 }, 0.2f);
				jump_neutral2.PushBack({ 367, 371, 75, 92 }, 0.2f);
				jump_neutral2.PushBack({ 446, 371, 78, 83 }, 0.2f);
				jump_neutral2.PushBack({ 209, 371, 75, 92 }, 0.2f);
				jump_neutral2.PushBack({ 288, 371, 75, 92 }, 0.2f);
				jump_neutral2.PushBack({ 367, 371, 75, 92 }, 0.2f);
				jump_neutral2.PushBack({ 15, 371, 60, 112 }, 0.2f); //1
				jump_neutral2.PushBack({ 80, 371, 60, 112 }, 0.2f);
				jump_neutral2.PushBack({ 145, 371, 60, 112 }, 0.2f);
				jump_neutral2.PushBack({ 527, 371, 68, 112 }, 0.2f); //8
				jump_neutral2.PushBack({ 601, 371, 68, 112 }, 0.2f); //9
				jump_neutral2.PushBack({ 674, 371, 68, 112 }, 0.2f); //10
			}

			//jump forward animation
			{
				jump_forward2.PushBack({ 15, 1362, 63, 130 }, 0.3f);
				jump_forward2.PushBack({ 83, 1362, 63, 130 }, 0.3f);
				jump_forward2.PushBack({ 151, 1362, 63, 130 }, 0.3f);
				jump_forward2.PushBack({ 224, 1362, 74, 93 }, 0.3f);
				jump_forward2.PushBack({ 307, 1362, 74, 93 }, 0.3f);
				jump_forward2.PushBack({ 391, 1362, 74, 93 }, 0.3f);
				jump_forward2.PushBack({ 478, 1362, 62, 81 }, 0.3f);
				jump_forward2.PushBack({ 559, 1362, 62, 81 }, 0.3f);
				jump_forward2.PushBack({ 631, 1362, 62, 81 }, 0.3f);
				jump_forward2.PushBack({ 706, 1362, 80, 62 }, 0.3f);
				jump_forward2.PushBack({ 799, 1362, 80, 62 }, 0.3f);
				jump_forward2.PushBack({ 888, 1362, 80, 62 }, 0.3f);
				jump_forward2.PushBack({ 981, 1362, 62, 81 }, 0.3f);
				jump_forward2.PushBack({ 1066, 1362, 62, 81 }, 0.3f);
				jump_forward2.PushBack({ 1152, 1362, 62, 81 }, 0.3f);
				jump_forward2.PushBack({ 1226, 1362, 80, 62 }, 0.3f);
				jump_forward2.PushBack({ 1312, 1362, 80, 62 }, 0.3f);
				jump_forward2.PushBack({ 1407, 1362, 80, 62 }, 0.3f);
				jump_forward2.PushBack({ 1509, 1362, 77, 85 }, 0.3f);
				jump_forward2.PushBack({ 1595, 1362, 77, 85 }, 0.3f);
				jump_forward2.PushBack({ 1686, 1362, 77, 85 }, 0.3f);
				jump_forward2.loop = false;
			}

			//jump backward animation
			{
				jump_backward2.PushBack({ 15, 1492, 63, 112 }, 0.3f);
				jump_backward2.PushBack({ 83, 1492, 63, 112 }, 0.3f);
				jump_backward2.PushBack({ 151, 1492, 63, 112 }, 0.3f);
				jump_backward2.PushBack({ 224, 1492, 74, 93 }, 0.3f);
				jump_backward2.PushBack({ 307, 1492, 74, 93 }, 0.3f);
				jump_backward2.PushBack({ 391, 1492, 74, 93 }, 0.3f);
				jump_backward2.PushBack({ 478, 1492, 80, 61 }, 0.3f);
				jump_backward2.PushBack({ 566, 1492, 80, 61 }, 0.3f);
				jump_backward2.PushBack({ 661, 1492, 80, 61 }, 0.3f);
				jump_backward2.PushBack({ 757, 1492, 62, 80 }, 0.3f);
				jump_backward2.PushBack({ 842, 1492, 62, 80 }, 0.3f);
				jump_backward2.PushBack({ 927, 1492, 62, 80 }, 0.3f);
				jump_backward2.PushBack({ 1013, 1492, 80, 61 }, 0.3f);
				jump_backward2.PushBack({ 1105, 1492, 80, 61 }, 0.3f);
				jump_backward2.PushBack({ 1195, 1492, 80, 61 }, 0.3f);
				jump_backward2.PushBack({ 1286, 1492, 62, 80 }, 0.3f);
				jump_backward2.PushBack({ 1367, 1492, 62, 80 }, 0.3f);
				jump_backward2.PushBack({ 1436, 1492, 62, 80 }, 0.3f);
				jump_backward2.PushBack({ 1509, 1492, 77, 85 }, 0.3f);
				jump_backward2.PushBack({ 1595, 1492, 77, 85 }, 0.3f);
				jump_backward2.PushBack({ 1686, 1492, 77, 85 }, 0.3f);
				jump_backward2.loop = false;
			}

			//punch animation
			{
				punch2.PushBack({ 14, 236, 69, 130 }, 0.5f);
				punch2.PushBack({ 87, 236, 69, 130 }, 0.3f);
				punch2.PushBack({ 164, 235, 79, 127 }, 0.3f);
				punch2.PushBack({ 243, 236, 79, 127 }, 0.5f);
				punch2.PushBack({ 331, 236, 79, 127 }, 0.5f);
				punch2.PushBack({ 410, 236, 129, 127 }, 0.5f);
				punch2.PushBack({ 545, 236, 130, 127 }, 0.5f);
				punch2.PushBack({ 679, 236, 130, 127 }, 0.5f);
				punch2.PushBack({ 814, 236, 129, 127 }, 0.5f); //9
				punch2.PushBack({ 946, 236, 130, 127 }, 0.5f);
				punch2.PushBack({ 1081, 236, 130, 127 }, 0.5f);
				punch2.PushBack({ 1213, 236, 120, 127 }, 0.5f);
				punch2.PushBack({ 1337, 236, 120, 127 }, 0.5f);
				punch2.PushBack({ 1461, 236, 83, 127 }, 0.8f);
				punch2.PushBack({ 1548, 236, 83, 127 }, 6.8f);
				punch2.PushBack({ 1635, 236, 83, 127 }, 6.8f); //16
				punch2.PushBack({ 1721, 236,131, 127 }, 6.7f);
				punch2.PushBack({ 1856, 236, 131, 127 }, 6.7f);
				punch2.loop = false;
			}

			//kick animation
			{
				kick2.PushBack({ 16,137,66,95 }, 0.8f); //initial kick frames
				kick2.PushBack({ 87,137,66,95 }, 0.8f);
				kick2.PushBack({ 158,137,66,95 }, 0.8f);
				kick2.PushBack({ 229,134,86,98 }, 0.6f); //final kick frames
				kick2.PushBack({ 320,134,86,98 }, 0.6f);
				kick2.PushBack({ 411,134,86,98 }, 0.6f);
				kick2.PushBack({ 16,137,66,95 }, 0.7f); //initial kick frames
				kick2.PushBack({ 87,137,66,95 }, 0.7f);
				kick2.PushBack({ 158,137,66,95 }, 0.7f);
				kick2.loop = false;
			}

			//get hit animation 2
			{
				hit2.PushBack({ 14, 1616, 78, 100 }, 0.3f);
				hit2.PushBack({ 105, 1616, 78, 100 }, 0.3f);
				hit2.PushBack({ 195, 1616, 78, 100 }, 0.3f);
				hit2.PushBack({ 282, 1616, 77, 94 }, 0.3f);
				hit2.PushBack({ 367, 1616, 77, 94 }, 0.3f);
				hit2.PushBack({ 452, 1616, 77, 94 }, 0.3f);
				hit2.PushBack({ 14, 1616, 78, 100 }, 6.3f);
				hit2.PushBack({ 105, 1616, 78, 100 }, 6.3f);
				hit2.PushBack({ 195, 1616, 78, 100 }, 6.3f);
				hit2.loop = false;
			}

			//crouch animation
			{
				crouch_down2.PushBack({ 15, 1239, 68, 110 }, 0.5f);
				crouch_down2.PushBack({ 94, 1239, 68, 110 }, 0.5f);
				crouch_down2.PushBack({ 180, 1239, 68, 110 }, 0.5f);
				crouch_down2.PushBack({ 299, 1273, 88, 76 }, 0.5f);
				crouch_down2.PushBack({ 431, 1273, 88, 76 }, 0.5f);
				crouch_down2.PushBack({ 557, 1273, 88, 76 }, 0.5f);
				crouch_down2.loop = false;

				crouch_up2.PushBack({ 180, 1239, 68, 110 }, 0.9f);
				crouch_up2.PushBack({ 94, 1239, 68, 110 }, 0.9f);
				crouch_up2.PushBack({ 15, 1239, 68, 110 }, 0.9f);
				crouch_up2.loop = false;
			}

			//crouch punch
			{
				crouch_punch2.PushBack({ 15, 1718, 100, 93 }, 0.6f);
				crouch_punch2.PushBack({ 102, 1718, 104, 93 }, 0.6f);
				crouch_punch2.PushBack({ 210, 1718, 109, 93 }, 0.6f);
				crouch_punch2.PushBack({ 324, 1718, 155, 90 }, 0.6f);
				crouch_punch2.PushBack({ 476, 1718, 155, 90 }, 0.6f);
				crouch_punch2.PushBack({ 640, 1718, 155, 91 }, 0.6f);
				crouch_punch2.PushBack({ 792, 1718, 154, 92 }, 0.6f);
				crouch_punch2.PushBack({ 953, 1718, 150, 94 }, 0.6f);
				crouch_punch2.PushBack({ 1129, 1718, 150, 93 }, 0.6f);
				crouch_punch2.PushBack({ 1287, 1718, 111, 93 }, 0.6f);
				crouch_punch2.PushBack({ 1411, 1718, 111, 93 }, 0.6f);
				crouch_punch2.PushBack({ 1539, 1718, 111, 93 }, 0.6f);
				crouch_punch2.PushBack({ 1660, 1718, 111, 93 }, 0.6f);
				crouch_punch2.PushBack({ 1786, 1718, 111, 93 }, 0.6f);
				crouch_punch2.PushBack({ 1901, 1718, 109, 93 }, 0.6f);
				crouch_punch2.loop = false;
			}

			//crouch kick
			{
				crouch_kick2.PushBack({ 12, 1830, 74, 77 }, 0.3f);
				crouch_kick2.PushBack({ 106, 1828, 74, 77 }, 0.3f);
				crouch_kick2.PushBack({ 203, 1826, 79, 81 }, 0.3f);
				crouch_kick2.PushBack({ 300, 1826, 79, 81 }, 0.3f);
				crouch_kick2.PushBack({ 395, 1835, 99, 73 }, 0.3f);
				crouch_kick2.PushBack({ 513, 1835, 99, 73 }, 0.3f);
				crouch_kick2.PushBack({ 643, 1825, 79, 80 }, 0.6f);
				crouch_kick2.PushBack({ 751, 1825, 79, 80 }, 0.6f);
				crouch_kick2.loop = false;
			}

			//twister animation
			{
				twister2.PushBack({ 15, 798, 90, 90 }, 0.6f);
				twister2.PushBack({ 106, 798, 90, 90 }, 0.6f);
				twister2.PushBack({ 197, 798, 90, 90 }, 0.6f);
				twister2.PushBack({ 289, 798, 71, 90 }, 0.6f);
				twister2.PushBack({ 362, 798, 71, 90 }, 0.6f);
				twister2.PushBack({ 435, 803, 74, 86 }, 0.6f);
				twister2.PushBack({ 511, 803, 74, 86 }, 0.6f);
				twister2.PushBack({ 586, 795, 59, 94 }, 0.6f);
				twister2.PushBack({ 646, 795, 59, 94 }, 0.6f);
				twister2.PushBack({ 709, 788, 93, 101 }, 0.6f);
				twister2.PushBack({ 809, 788, 93, 101 }, 0.6f);
				twister2.PushBack({ 909, 788, 93, 101 }, 0.6f);
				twister2.PushBack({ 1006, 734, 62, 155 }, 0.6f);
				twister2.PushBack({ 1071, 734, 62, 155 }, 0.6f);
				twister2.PushBack({ 1138, 734, 62, 155 }, 0.6f);
				twister2.PushBack({ 1203, 787, 100, 102 }, 0.6f);
				twister2.PushBack({ 1313, 787, 100, 102 }, 0.6f);
				twister2.PushBack({ 1429, 787, 100, 102 }, 0.6f);
				twister2.PushBack({ 1543, 795, 98, 94 }, 0.6f);
				twister2.PushBack({ 1646, 795, 98, 94 }, 0.6f);
				twister2.PushBack({ 1749, 795, 98, 94 }, 0.6f);
				twister2.PushBack({ 15, 923, 104, 93 }, 0.6f);
				twister2.PushBack({ 121, 923, 104, 93 }, 0.6f);
				twister2.PushBack({ 228, 923, 104, 93 }, 0.6f);
				twister2.PushBack({ 337, 923, 84, 93 }, 0.6f);
				twister2.PushBack({ 425, 923, 84, 93 }, 0.6f);
				twister2.PushBack({ 512, 923, 84, 93 }, 0.6f);
				twister2.PushBack({ 599, 896, 72, 120 }, 0.6f);
				twister2.PushBack({ 673, 896, 72, 120 }, 0.6f);
				twister2.PushBack({ 748, 896, 72, 120 }, 0.6f);
				twister2.loop = false;

				//Twister animation (only the twister)
				twisterAlone2.loop = false;
			}
			{
				die2.PushBack({ 852,0,108,54 });
			}
			//en garde 2
			{
				en_garde2.PushBack({ 14, 1921, 74,113 }, 0.15f);
				en_garde2.PushBack({ 95, 1921, 78,113 }, 0.15f);
				en_garde2.PushBack({ 182, 1921, 79,113 }, 0.15f);
				en_garde2.PushBack({ 264, 1921, 79,113 }, 0.15f);
				en_garde2.PushBack({ 346, 1921, 81,113 }, 0.15f);
				en_garde2.PushBack({ 433, 1921, 78,113 }, 0.15f);
				en_garde2.PushBack({ 517, 1921, 79,113 }, 0.15f);
				en_garde2.PushBack({ 595, 1921, 74,113 }, 0.15f);
				en_garde2.PushBack({ 677, 1921, 73,113 }, 0.15f);
				en_garde2.PushBack({ 164, 235, 79, 127 }, 0.15f);
				en_garde2.PushBack({ 243, 236, 79, 127 }, 0.15f);
				//punch
				en_garde2.PushBack({ 1721, 236,131, 127 }, 0.4f);
				en_garde2.PushBack({ 1856, 236, 131, 127 }, 0.4f);
				en_garde2.PushBack({ 1461, 236, 83, 127 }, 0.4f);
				en_garde2.PushBack({ 1721, 236,131, 127 }, 0.4f);
				en_garde2.loop = false;
			}
			//win 2
			{
				win2.PushBack({ 48, 2072, 76, 177 }, 0.15f);
				win2.PushBack({ 146, 2072, 76, 177 }, 0.15f);
				win2.PushBack({ 248, 2079, 90, 170 }, 0.15f);
				win2.PushBack({ 338, 2071, 90, 178 }, 0.15f);
				win2.PushBack({ 436, 2040, 76, 209 }, 0.15f);
				win2.PushBack({ 537, 2040, 76, 209 }, 0.15f);
				win2.PushBack({ 628, 2040, 74, 209 }, 0.15f);
				win2.PushBack({ 729 , 2040, 74, 209 }, 0.15f);
				win2.PushBack({ 825, 2040, 74, 209 }, 0.15f);
				win2.PushBack({ 921, 2040, 74, 209 }, 0.15f);
				win2.PushBack({ 1023, 2131, 74, 118 }, 0.15f);
				win2.PushBack({ 1123, 2146, 49, 102 }, 0.15f);
				win2.PushBack({ 1180, 2142, 96, 106 }, 0.15f);
				win2.PushBack({ 1288, 2142, 96, 106 }, 0.15f);
				win2.PushBack({ 1409, 2142, 96, 106 }, 0.15f);
				win2.PushBack({ 1515, 2142, 96, 106 }, 0.15f);
				win2.PushBack({ 1614, 2142, 96, 106 }, 0.15f);
				win2.PushBack({ 1722, 2142, 96, 106 }, 0.15f);
				win2.PushBack({ 1838, 2142, 97, 106 }, 0.15f);
				win2.PushBack({ 26, 2357, 96, 106 }, 0.15f);
				win2.PushBack({ 140, 2357, 96, 106 }, 0.15f);
				win2.PushBack({ 258, 2357, 98, 106 }, 0.15f);
				win2.PushBack({ 381, 2357, 96, 106 }, 0.15f);
				win2.PushBack({ 483, 2357, 96, 106 }, 0.15f);
				win2.PushBack({ 575, 2357, 96, 106 }, 0.15f);
				win2.PushBack({ 680, 2357, 96, 106 }, 0.15f);
				win2.PushBack({ 804, 2254, 98, 209 }, 0.15f);
				win2.PushBack({ 912, 2254, 98, 209 }, 0.15f);
				win2.PushBack({ 1004, 2254, 96, 209 }, 0.15f);
				win2.PushBack({ 1103, 2254, 96, 209 }, 0.15f);
				win2.PushBack({ 1195, 2254, 96, 209 }, 0.15f);
				win2.PushBack({ 1291, 2254, 96, 209 }, 0.15f);
				win2.PushBack({ 1407, 2254, 100, 209 }, 0.15f);
				win2.PushBack({ 1523, 2254, 100, 209 }, 0.15f);
				win2.PushBack({ 1630, 2254, 96, 209 }, 0.15f);
				win2.PushBack({ 1746, 2254, 96, 209 }, 0.15f);
				win2.PushBack({ 1840, 2254, 96, 209 }, 0.15f);
				win2.PushBack({ 49, 2488, 96, 190 }, 0.15f);
				win2.PushBack({ 158, 2498, 96, 180 }, 0.15f);
				win2.PushBack({ 255, 2503, 96, 175 }, 0.15f);
				win2.PushBack({ 356, 2513, 96, 165 }, 0.15f);
				win2.PushBack({ 452, 2521, 96, 157 }, 0.15f);
				win2.PushBack({ 553, 2530, 96, 148 }, 0.15f);
				win2.PushBack({ 646, 2566, 96, 112 }, 0.15f);
				win2.PushBack({ 741, 2566, 96, 112 }, 0.15f);
				win2.PushBack({ 1028, 2566, 96, 112 }, 0.15f);
				win2.loop = false;
			}

		}
	}
}

bool ModuleWanFu::Start() {
	player2_textures = App->textures->Load("Assets/Sprites/Characters/Wan-Fu/Wan-Fu.png");
	return true;
}

bool ModuleWanFu::CleanUp() {
	App->textures->Unload(player2_textures);
	return true;
}