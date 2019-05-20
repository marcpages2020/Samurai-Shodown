#include "ModulePlayer2.h"
#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModuleSceneHaohmaru.h"
#include "ModuleUI.h"

ModulePlayer2::ModulePlayer2()
{
	//animations
	{
		//Haohmaru  
		/*
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

			crouch_up2.PushBack({ 180, 12439, 68, 110 }, 0.5f);
			crouch_up2.PushBack({ 94, 12439, 68, 110 }, 0.5f);
			crouch_up2.PushBack({ 15, 1239, 68, 110 }, 0.5f);
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
		*/
		// Wanf-Fu
		{
			//idle
			{
				idle2.PushBack({ 28,26,118,126 }, 0.2f); //01
				idle2.PushBack({ 150,26,118,126 }, 0.2f);
				idle2.PushBack({ 272,26,118,126 }, 0.2f);
				idle2.PushBack({ 394,26,118,126 }, 0.2f); //04
				idle2.PushBack({ 514,26,118,126 }, 0.2f);
				idle2.PushBack({ 635,26,118,126 }, 0.2f);
				idle2.PushBack({ 754,40,118,112 }, 0.2f); //07
				idle2.PushBack({ 873,40,118,112 }, 0.2f);
				idle2.PushBack({ 991,40,118,112 }, 0.2f);
				idle2.PushBack({ 394,26,118,126 }, 0.2f); //04
				idle2.PushBack({ 514,26,118,126 }, 0.2f);
				idle2.PushBack({ 635,26,118,126 }, 0.2f);
				idle2.loop = true;
			}
			// forward
			{
				forward2.PushBack({ 28,162,106,126 }, 0.3f);
				forward2.PushBack({ 137,162,106,126 }, 0.3f);
				forward2.PushBack({ 245,162,106,126 }, 0.3f);
				forward2.PushBack({ 353,162,106,126 }, 0.3f);
				forward2.PushBack({ 461,162,106,126 }, 0.3f);
				forward2.PushBack({ 569,162,106,126 }, 0.3f);
				forward2.PushBack({ 678,162,106,126 }, 0.3f);
				forward2.PushBack({ 786,162,106,126 }, 0.3f);
				forward2.PushBack({ 895,162,109,126 }, 0.3f);
				forward2.PushBack({ 1008,162,109,126 }, 0.3f);
				forward2.PushBack({ 1121,162,109,126 }, 0.3f);
				forward2.PushBack({ 1232,162,112,126 }, 0.3f);
				forward2.PushBack({ 1347,162,112,126 }, 0.3f);
				forward2.PushBack({ 1462,162,112,126 }, 0.3f);
				forward2.PushBack({ 1578,162,112,126 }, 0.3f);
				forward2.PushBack({ 1693,162,113,126 }, 0.3f);
				forward2.PushBack({ 1810,162,113,126 }, 0.3f);
				forward2.PushBack({ 1926,162,114,126 }, 0.3f);
				forward2.loop = true;
			}
			// backward
			{
				backward2.PushBack({ 28,162,106,126 }, 0.3f);
				backward2.PushBack({ 137,162,106,126 }, 0.3f);
				backward2.PushBack({ 245,162,106,126 }, 0.3f);
				backward2.PushBack({ 353,162,106,126 }, 0.3f);
				backward2.PushBack({ 461,162,106,126 }, 0.3f);
				backward2.PushBack({ 569,162,106,126 }, 0.3f);
				backward2.PushBack({ 678,162,106,126 }, 0.3f);
				backward2.PushBack({ 786,162,106,126 }, 0.3f);
				backward2.PushBack({ 895,162,109,126 }, 0.3f);
				backward2.PushBack({ 1008,162,109,126 }, 0.3f);
				backward2.PushBack({ 1121,162,109,126 }, 0.3f);
				backward2.PushBack({ 1232,162,112,126 }, 0.3f);
				backward2.PushBack({ 1347,162,112,126 }, 0.3f);
				backward2.PushBack({ 1462,162,112,126 }, 0.3f);
				backward2.PushBack({ 1578,162,112,126 }, 0.3f);
				backward2.PushBack({ 1693,162,113,126 }, 0.3f);
				backward2.PushBack({ 1810,162,113,126 }, 0.3f);
				backward2.PushBack({ 1926,162,114,126 }, 0.3f);
				backward2.loop = true;
			}
			// jump neutral
			{
				jump_neutral2.PushBack({ 28,305,106,139 }, 0.2f); //1
				jump_neutral2.PushBack({ 138,305,106,139 }, 0.2f);
				jump_neutral2.PushBack({ 248,305,106,139 }, 0.2f);
				jump_neutral2.PushBack({ 357,296,106,103 }, 0.2f); //4
				jump_neutral2.PushBack({ 467,296,106,103 }, 0.2f);
				jump_neutral2.PushBack({ 577,296,106,103 }, 0.2f);
				jump_neutral2.PushBack({ 685,296,107,83 }, 0.2f); //7
				jump_neutral2.PushBack({ 795,296,106,103 }, 0.2f);
				jump_neutral2.PushBack({ 905,296,106,103 }, 0.2f);
				jump_neutral2.PushBack({ 357,296,106,103 }, 0.2f); //4
				jump_neutral2.PushBack({ 467,296,106,103 }, 0.2f);
				jump_neutral2.PushBack({ 577,296,106,103 }, 0.2f);
				jump_neutral2.PushBack({ 28,305,106,139 }, 0.2f); //1
				jump_neutral2.PushBack({ 138,305,106,139 }, 0.2f);
				jump_neutral2.PushBack({ 248,305,106,139 }, 0.2f);
				jump_neutral2.loop = false;
			}
			// jump forward
			{
				jump_forward2.PushBack({ 28,305,106,139 }, 0.2f); //1
				jump_forward2.PushBack({ 138,305,106,139 }, 0.2f);
				jump_forward2.PushBack({ 248,305,106,139 }, 0.2f);
				jump_forward2.PushBack({ 357,296,106,103 }, 0.2f); //4
				jump_forward2.PushBack({ 467,296,106,103 }, 0.2f);
				jump_forward2.PushBack({ 577,296,106,103 }, 0.2f);
				jump_forward2.PushBack({ 685,296,107,83 }, 0.2f); //7
				jump_forward2.PushBack({ 795,296,106,103 }, 0.2f);
				jump_forward2.PushBack({ 905,296,106,103 }, 0.2f);
				jump_forward2.PushBack({ 357,296,106,103 }, 0.2f); //4
				jump_forward2.PushBack({ 467,296,106,103 }, 0.2f);
				jump_forward2.PushBack({ 577,296,106,103 }, 0.2f);
				jump_forward2.PushBack({ 28,305,106,139 }, 0.2f); //1
				jump_forward2.PushBack({ 138,305,106,139 }, 0.2f);
				jump_forward2.PushBack({ 248,305,106,139 }, 0.2f);
				jump_forward2.loop = false;
			}
			// jump backward
			{
				jump_backward2.PushBack({ 28,305,106,139 }, 0.2f); //1
				jump_backward2.PushBack({ 138,305,106,139 }, 0.2f);
				jump_backward2.PushBack({ 248,305,106,139 }, 0.2f);
				jump_backward2.PushBack({ 357,296,106,103 }, 0.2f); //4
				jump_backward2.PushBack({ 467,296,106,103 }, 0.2f);
				jump_backward2.PushBack({ 577,296,106,103 }, 0.2f);
				jump_backward2.PushBack({ 685,296,107,83 }, 0.2f); //7
				jump_backward2.PushBack({ 795,296,106,103 }, 0.2f);
				jump_backward2.PushBack({ 905,296,106,103 }, 0.2f);
				jump_backward2.PushBack({ 357,296,106,103 }, 0.2f); //4
				jump_backward2.PushBack({ 467,296,106,103 }, 0.2f);
				jump_backward2.PushBack({ 577,296,106,103 }, 0.2f);
				jump_backward2.PushBack({ 28,305,106,139 }, 0.2f); //1
				jump_backward2.PushBack({ 138,305,106,139 }, 0.2f);
				jump_backward2.PushBack({ 248,305,106,139 }, 0.2f);
				jump_backward2.loop = false;
			}
			//kick
			{
				kick2.PushBack({ 28,745,108,148 }, 0.5f);//1
				kick2.PushBack({ 139,745,108,148 }, 0.5f);
				kick2.PushBack({ 249,745,108,148 }, 0.5f);
				kick2.PushBack({ 358,745,99,148 }, 0.5f);//4
				kick2.PushBack({ 459,745,99,148 }, 0.5f);
				kick2.PushBack({ 560,745,99,148 }, 0.5f);
				kick2.PushBack({ 660,745,99,148 }, 0.5f);//7
				kick2.PushBack({ 762,745,99,148 }, 0.5f);
				kick2.PushBack({ 863,745,99,148 }, 0.5f);
				kick2.PushBack({ 964,745,99,148 }, 0.5f);//10
				kick2.PushBack({ 1067,745,99,148 }, 0.5f);
				kick2.PushBack({ 1168,745,99,148 }, 0.5f);
				kick2.PushBack({ 660,745,99,148 }, 0.5f);//7
				kick2.PushBack({ 762,745,99,148 }, 0.5f);
				kick2.PushBack({ 863,745,99,148 }, 0.5f);
				kick2.PushBack({ 358,745,99,148 }, 0.5f);//4
				kick2.PushBack({ 459,745,99,148 }, 0.5f);
				kick2.PushBack({ 560,745,99,148 }, 0.5f);
				kick2.PushBack({ 28,745,108,148 }, 0.5f);//1
				kick2.PushBack({ 139,745,108,148 }, 0.5f);
				kick2.PushBack({ 249,745,108,148 }, 0.5f);
				kick2.loop = false;
			}
			//punch
			{
				punch2.PushBack({ 27, 451, 87, 168 }, 0.5f);
				punch2.PushBack({ 116, 451, 87, 168 }, 0.5f);
				punch2.PushBack({ 207, 492, 134, 127 }, 0.5f);
				punch2.PushBack({ 342, 492, 134, 127 }, 0.5f);
				punch2.PushBack({ 477, 474, 134, 143 }, 0.5f);
				punch2.PushBack({ 614, 474, 134, 143 }, 0.5f);
				punch2.PushBack({ 751, 490, 132, 128 }, 0.5f);
				punch2.PushBack({ 891, 490, 132, 128 }, 0.5f);
				punch2.PushBack({ 1031, 530, 136, 89 }, 0.5f);
				punch2.PushBack({ 1172, 530, 136, 89 }, 0.5f);
				punch2.PushBack({ 1313, 542, 133, 75 }, 0.5f);
				punch2.PushBack({ 1449, 542, 133, 75 }, 0.5f);
				punch2.PushBack({ 1587, 542, 133, 75 }, 0.5f);
				punch2.PushBack({ 1724, 542, 133, 75 }, 0.5f);
				punch2.PushBack({ 1861, 542, 133, 75 }, 0.5f);
				punch2.PushBack({ 27, 620, 103, 125 }, 0.5f);
				punch2.PushBack({ 133, 620, 103, 125 }, 0.5f);
				punch2.PushBack({ 237, 620, 103, 125 }, 0.5f);
				punch2.PushBack({ 341, 620, 103, 125 }, 0.5f);
				punch2.PushBack({ 447, 620, 103, 125 }, 0.5f);
				punch2.loop = false;
			}

			//crouch down
			{
				crouch_down2.PushBack({ 1355, 28, 107, 124 }, 0.5f);
				crouch_down2.PushBack({ 1466, 28, 107, 124 }, 0.5f);
				crouch_down2.PushBack({ 1578, 28, 107, 124 }, 0.5f);
				crouch_down2.PushBack({ 1691, 58, 107, 93 }, 0.5f);
				crouch_down2.PushBack({ 1803, 58, 107, 93 }, 0.5f);
				crouch_down2.PushBack({ 1914, 58, 107, 93 }, 0.5f);
				crouch_down2.loop = false;
			}

			//crouch up
			{
				crouch_up2.PushBack({ 1355, 28, 107, 124 }, 0.5f);
				crouch_up2.PushBack({ 1466, 28, 107, 124 }, 0.5f);
				crouch_up2.PushBack({ 1578, 28, 107, 124 }, 0.5f);
				crouch_up2.loop = false;
			}

			//crouch kick
			{
				crouch_kick2.PushBack({ 1190, 332, 107, 112 }, 0.5f);
				crouch_kick2.PushBack({ 1303, 332, 107, 112 }, 0.5f);
				crouch_kick2.PushBack({ 1414, 340, 112, 104 }, 0.5f);
				crouch_kick2.PushBack({ 1532, 334, 130, 110 }, 0.5f);
				crouch_kick2.PushBack({ 1667, 334, 130, 110 }, 0.5f);
				crouch_kick2.PushBack({ 1803, 339, 112, 105 }, 0.5f);
				crouch_kick2.PushBack({ 1921, 339, 112, 105 }, 0.5f);
				crouch_kick2.loop = false;
			}

			//crouch punch
			{
				crouch_punch2.PushBack({ 28, 1082, 119, 128 }, 0.5f);
				crouch_punch2.PushBack({ 146, 1082, 119, 128 }, 0.5f);
				crouch_punch2.PushBack({ 264, 1075, 117, 135 }, 0.5f);
				crouch_punch2.PushBack({ 381, 1075, 117, 135 }, 0.5f);
				crouch_punch2.PushBack({ 497, 1075, 117, 135 }, 0.5f);
				crouch_punch2.PushBack({ 614, 1044, 138, 167 }, 0.5f);
				crouch_punch2.PushBack({ 752, 1047, 138, 164 }, 0.5f);
				crouch_punch2.PushBack({ 891, 1047, 138, 164 }, 0.5f);
				crouch_punch2.PushBack({ 1046, 1172, 157, 129 }, 0.5f);
				crouch_punch2.PushBack({ 1203, 1123, 138, 88 }, 0.5f);
				crouch_punch2.PushBack({ 1340, 1123, 138, 88 }, 0.5f);
				crouch_punch2.PushBack({ 1480, 1084, 102, 126 }, 0.5f);
				crouch_punch2.PushBack({ 1593, 1084, 102, 126 }, 0.5f);
				crouch_punch2.PushBack({ 1701, 1084, 102, 126 }, 0.5f);
				crouch_punch2.loop = false;

			}
			//hit
			{
				hit2.PushBack({ 28,1227,127,156 }, 0.3f);//1
				hit2.PushBack({ 162,1227,127,156 }, 0.3f);
				hit2.PushBack({ 296,1227,127,156 }, 0.3f);
				hit2.PushBack({ 429,1227,173,156 }, 0.3f);//4
				hit2.PushBack({ 609,1227,173,156 }, 0.3f);
				hit2.PushBack({ 788,1227,173,156 }, 0.3f);
				hit2.PushBack({ 28,1227,127,156 }, 0.3f);//1
				hit2.PushBack({ 162,1227,127,156 }, 0.3f);
				hit2.PushBack({ 296,1227,127,156 }, 0.3f);
				hit2.loop = false;
			}
			//special attack
			{
				specialattack2.PushBack({ 34, 1395, 73, 170 }, 0.1f);//1
				specialattack2.PushBack({ 160, 1395, 73, 170 }, 0.1f);
				specialattack2.PushBack({ 272, 1395, 73, 170 }, 0.1f);
				specialattack2.PushBack({ 380, 1395, 117, 92 }, 0.25f);//4
				specialattack2.PushBack({ 527, 1395, 116, 85 }, 0.25f);
				specialattack2.PushBack({ 674, 1395, 113, 78 }, 0.25f);
				specialattack2.PushBack({ 791, 1395, 100, 55 }, 0.35f);//7
				specialattack2.PushBack({ 913, 1395, 99, 52 }, 0.35f);
				specialattack2.PushBack({ 1045, 1395, 96, 49 }, 0.35f);
				specialattack2.PushBack({ 1165, 1395, 69, 45 }, 0.8f);//10
				specialattack2.PushBack({ 1271, 1395, 69, 45 }, 0.8f);//11
				specialattack2.PushBack({ 1379, 1395, 69, 45 }, 0.8f);
				specialattack2.PushBack({ 1488, 1395, 63, 46 }, 0.8f);
				specialattack2.PushBack({ 1583, 1395, 63, 47 }, 0.8f);
				specialattack2.PushBack({ 1667, 1395, 63, 50 }, 0.8f);//15
				specialattack2.PushBack({ 1757, 1395, 63, 52 }, 0.8f);//16
				specialattack2.PushBack({ 1847, 1395, 63, 57 }, 0.7f);
				specialattack2.PushBack({ 1930, 1395, 103, 55 }, 0.7f);
				specialattack2.PushBack({ 29, 1574, 103, 58 }, 0.7f);//19
				specialattack2.PushBack({ 168, 1574, 128, 62 }, 0.7f);
				specialattack2.PushBack({ 310, 1574, 91, 68 }, 0.7f);
				specialattack2.PushBack({ 429, 1574, 91, 73 }, 0.7f);//22
				specialattack2.PushBack({ 548, 1574, 91, 79 }, 0.7f);
				specialattack2.PushBack({ 679, 1574, 62, 94 }, 0.05f);//24
				specialattack2.PushBack({ 795, 1574, 88, 121 }, 0.01f);//25
				specialattack2.loop = false;
			}

			//jump_kick
			{
				jump_kick2.PushBack({ 28,745,108,148 }, 0.5f);//1
				jump_kick2.PushBack({ 139,745,108,148 }, 0.5f);
				jump_kick2.PushBack({ 249,745,108,148 }, 0.5f);
				jump_kick2.PushBack({ 358,745,99,148 }, 0.5f);//4
				jump_kick2.PushBack({ 459,745,99,148 }, 0.5f);
				jump_kick2.PushBack({ 560,745,99,148 }, 0.5f);
				jump_kick2.PushBack({ 660,745,99,148 }, 0.5f);//7
				jump_kick2.PushBack({ 762,745,99,148 }, 0.5f);
				jump_kick2.PushBack({ 863,745,99,148 }, 0.5f);
				jump_kick2.PushBack({ 964,745,99,148 }, 0.5f);//10
				jump_kick2.PushBack({ 1067,745,99,148 }, 0.5f);
				jump_kick2.PushBack({ 1168,745,99,148 }, 0.5f);
				jump_kick2.PushBack({ 660,745,99,148 }, 0.5f);//7
				jump_kick2.PushBack({ 762,745,99,148 }, 0.5f);
				jump_kick2.PushBack({ 863,745,99,148 }, 0.5f);
				jump_kick2.PushBack({ 358,745,99,148 }, 0.5f);//4
				jump_kick2.PushBack({ 459,745,99,148 }, 0.5f);
				jump_kick2.PushBack({ 560,745,99,148 }, 0.5f);
				jump_kick2.PushBack({ 28,745,108,148 }, 0.5f);//1
				jump_kick2.PushBack({ 139,745,108,148 }, 0.5f);
				jump_kick2.PushBack({ 249,745,108,148 }, 0.5f);
				jump_kick2.loop = false;
			}

			//jump_punch
			{
				jump_punch2.PushBack({ 27, 451, 87, 168 }, 0.5f);
				jump_punch2.PushBack({ 116, 451, 87, 168 }, 0.5f);
				jump_punch2.PushBack({ 207, 492, 134, 127 }, 0.5f);
				jump_punch2.PushBack({ 342, 492, 134, 127 }, 0.5f);
				jump_punch2.PushBack({ 477, 474, 134, 143 }, 0.5f);
				jump_punch2.PushBack({ 614, 474, 134, 143 }, 0.5f);
				jump_punch2.PushBack({ 751, 490, 132, 128 }, 0.5f);
				jump_punch2.PushBack({ 891, 490, 132, 128 }, 0.5f);
				jump_punch2.PushBack({ 1031, 530, 136, 89 }, 0.5f);
				jump_punch2.PushBack({ 1172, 530, 136, 89 }, 0.5f);
				jump_punch2.PushBack({ 1313, 542, 133, 75 }, 0.5f);
				jump_punch2.PushBack({ 1449, 542, 133, 75 }, 0.5f);
				jump_punch2.PushBack({ 1587, 542, 133, 75 }, 0.5f);
				jump_punch2.PushBack({ 1724, 542, 133, 75 }, 0.5f);
				jump_punch2.PushBack({ 1861, 542, 133, 75 }, 0.5f);
				jump_punch2.PushBack({ 27, 620, 103, 125 }, 0.5f);
				jump_punch2.PushBack({ 133, 620, 103, 125 }, 0.5f);
				jump_punch2.PushBack({ 237, 620, 103, 125 }, 0.5f);
				jump_punch2.PushBack({ 341, 620, 103, 125 }, 0.5f);
				jump_punch2.PushBack({ 447, 620, 103, 125 }, 0.5f);
				jump_punch2.loop = false;
			}

			//win animation
			{
				win2.PushBack({ 39, 1711, 111, 117 }, 0.1f);
				win2.PushBack({ 180, 1711, 111, 117 }, 0.1f);
				win2.PushBack({ 331, 1711, 111, 117 }, 0.1f);
				win2.PushBack({ 478, 1711, 111, 118 }, 0.1f);
				win2.PushBack({ 618, 1711, 111, 118 }, 0.1f);
				win2.PushBack({ 757, 1711, 111, 118 }, 0.1f);
				win2.PushBack({ 895, 1711, 111, 116 }, 0.1f);
				win2.PushBack({ 1031, 1711, 111, 116 }, 0.1f);
				win2.PushBack({ 1171, 1711, 111, 116 }, 0.1f);
				win2.PushBack({ 1302, 1711, 111, 120 }, 0.1f);
				win2.PushBack({ 1432, 1711, 111, 120 }, 0.1f);
				win2.PushBack({ 1556, 1711, 111, 120 }, 0.1f);
				win2.loop = true;
			}

			//en garde
			{
				en_garde2.PushBack({ 28,901,119,126 }, 0.2f);
				en_garde2.PushBack({ 152,901,119,126 }, 0.2f);
				en_garde2.PushBack({ 275,901,119,126 }, 0.2f);
				en_garde2.PushBack({ 399,901,119,126 }, 0.2f);
				en_garde2.PushBack({ 526,901,119,126 }, 0.2f);
				en_garde2.PushBack({ 654,901,119,126 }, 0.2f);
				en_garde2.PushBack({ 778,901,119,126 }, 0.2f);
				en_garde2.PushBack({ 903,901,119,126 }, 0.2f);
				en_garde2.PushBack({ 1027,901,119,126 }, 0.2f);
				en_garde2.loop = false;
			}
		}
	}
}

ModulePlayer2::~ModulePlayer2() {}

// Load assets
bool ModulePlayer2::Start()
{
	bool ret = true;
	LOG("Loading player 2\n");
	position.x = initial_position.x = shadow_x = 305;
	position.y = initial_position.y = 215;
	lposition = position;
	light_attack_fx = App->audio->LoadFX("Assets/Audio/Fx/Characters/Haohmaru/light_attack.wav");
	light_kick_fx = App->audio->LoadFX("Assets/Audio/Fx/Characters/Haohmaru/light_kick.wav");
	twister_fx = App->audio->LoadFX("Assets/Audio/Fx/Characters/Haohmaru/twister.wav");
	//hit_fx = App->audio->LoadFX("Assets/Audio/FX/Characters/Haohmaru/Hit_1.wav");
	hit_fx = App->audio->LoadFX("Assets/Audio/FX/Characters/Wan-Fu/Hit_1.wav");
	special_attack_fx = App->audio->LoadFX("Assets/Audio/FX/Characters/Wan-Fu/special_attack.wav");
	state2 = IDLE2;
	god = false;
	life = 100;
	current_animation = &idle2;
	if (!collider_player_2_up)
		collider_player_2_up = App->collision->AddCollider({ position.x + 15, position.y - 85,30,40 }, COLLIDER_PLAYER_2, (Module*)App->player2);
	if (!collider_player_2_down)
		collider_player_2_down = App->collision->AddCollider({ position.x + 10, position.y - 45,40,45 }, COLLIDER_PLAYER_2, (Module*)App->player2);
	App->ui->Enable();
	return ret;
}

update_status ModulePlayer2::PreUpdate()
{
	if (!App->is_paused) {
		if (controls) {
			player_input2.pressing_left = App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_REPEAT || SDL_GameControllerGetAxis(App->input->controller_player_2, SDL_CONTROLLER_AXIS_LEFTX) <= -10000;
			player_input2.pressing_right = App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_REPEAT || SDL_GameControllerGetAxis(App->input->controller_player_2, SDL_CONTROLLER_AXIS_LEFTX) >= 10000;
			player_input2.pressing_down = App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_REPEAT || SDL_GameControllerGetAxis(App->input->controller_player_2, SDL_CONTROLLER_AXIS_LEFTY) >= 10000;
			player_input2.pressing_up = App->input->keyboard[SDL_SCANCODE_UP] == KEY_DOWN || SDL_GameControllerGetAxis(App->input->controller_player_2, SDL_CONTROLLER_AXIS_LEFTY) <= -10000;
			player_input2.pressing_J = App->input->keyboard[SDL_SCANCODE_J] == KEY_DOWN || App->input->game_pad[SDL_CONTROLLER_BUTTON_A][GAME_PAD_2] == KEY_DOWN;
			player_input2.pressing_K = App->input->keyboard[SDL_SCANCODE_K] == KEY_DOWN || App->input->game_pad[SDL_CONTROLLER_BUTTON_B][GAME_PAD_2] == KEY_DOWN;
			player_input2.pressing_L = App->input->keyboard[SDL_SCANCODE_L] == KEY_DOWN || App->input->game_pad[SDL_CONTROLLER_BUTTON_X][GAME_PAD_2] == KEY_DOWN;

			if (player_input2.pressing_left && player_input2.pressing_right) {
				player_input2.pressing_left = false;
				player_input2.pressing_right = false;
			}

		}


		if (state2 == IDLE2) {
			if (player_input2.pressing_left)
				state2 = FORWARD2;
			if (player_input2.pressing_right)
				state2 = BACKWARD2;
			if (player_input2.pressing_J) {
				hit_done++;
				state2 = KICK2;
				App->audio->PlayFX(light_kick_fx);
			}
			if (player_input2.pressing_K) {
				hit_done++;
				state2 = PUNCH2;
				App->audio->PlayFX(light_attack_fx);
			}
			if (player_input2.pressing_up)
				state2 = JUMP_NEUTRAL2;
			if (player_input2.pressing_down)
				state2 = CROUCH_DOWN2;
			if (player_input2.pressing_L) {
				hit_done++;
				//App->audio->PlayFX(twister_fx);
				App->audio->PlayFX(special_attack_fx);
				//state2 = TWISTER2;
				state2 = SPECIAL_ATTACK_2;
			}
		}
		if (state2 == BACKWARD2) {
			if (!player_input2.pressing_right)
				state2 = IDLE2;
			if (player_input2.pressing_K) {
				hit_done++;
				state2 = PUNCH2;
			}

			if (player_input2.pressing_J) {
				hit_done++;
				state2 = KICK2;
			}

			if (player_input2.pressing_up)
				state2 = JUMP_BACKWARD2;
		}
		if (state2 == FORWARD2) {
			if (!player_input2.pressing_left)
				state2 = IDLE2;
			if (player_input2.pressing_K) {
				hit_done++;
				state2 = PUNCH2;
			}

			if (player_input2.pressing_J) {
				hit_done++;
				state2 = KICK2;
			}

			if (player_input2.pressing_up)
				state2 = JUMP_FORWARD2;
		}
		if (state2 == KICK2) {
			if (current_animation->Finished()) {
				state2 = IDLE2;
				kick2.Reset();
				if (collider_player_2_mid != nullptr)
				{
					collider_player_2_mid->to_delete = true;
				}
			}
		}
		if (state2 == PUNCH2) {
			if (current_animation->Finished()) {
				state2 = IDLE2;
				punch2.Reset();
			}
		}
		if (state2 == JUMP_NEUTRAL2)
		{
			if (player_input2.pressing_J) {
				state2 = JUMP_KICK2;
				//hit_done++;
			}
			if (player_input2.pressing_K) {
				//hit_done++;
				state2 = JUMP_PUNCH2;
				direction_x = 0;
			}
			if (player_input2.pressing_right && mult == 1)
				state2 = JUMP_BACKWARD2;
			if (player_input2.pressing_left && mult == 1)
				state2 = JUMP_FORWARD2;
			if (current_animation->Finished())
			{
				state2 = IDLE2;
				jump_neutral2.Reset();
			}
		}
		if (state2 == JUMP_FORWARD2)
		{
			if (player_input2.pressing_J) {
				state2 = JUMP_KICK2;
				//hit_done++;
			}
			if (player_input2.pressing_K) {
				//hit_done++;
				state2 = JUMP_PUNCH2;
			}
			if (current_animation->Finished())
			{
				state2 = IDLE2;
				jump_forward2.Reset();
			}
			direction_x = 1;
		}
		if (state2 == JUMP_BACKWARD2)
		{
			if (player_input2.pressing_J) {
				state2 = JUMP_KICK2;
				//hit_done++;
			}
			if (player_input2.pressing_K) {
				//hit_done++;
				state2 = JUMP_PUNCH2;
				//App->audio->PlayFX(light_attack_fx);
			}
			if (current_animation->Finished())
			{
				state2 = IDLE2;
				jump_backward2.Reset();
			}
			direction_x = -1;
		}
		if (state2 == JUMP_PUNCH2) {
			if (current_animation->Finished())
			{
				state2 = IDLE2;
				jump_punch2.Reset();
			}
		}
		if (state2 == JUMP_KICK2) {
			if (current_animation->Finished())
			{
				state2 = IDLE2;
				jump_kick2.Reset();
			}
		}
		if (state2 == CROUCH_DOWN2)
		{
			if (!player_input2.pressing_down)
			{
				state2 = CROUCH_UP2;
				crouch_down2.Reset();
			}
			if (player_input2.pressing_J) {
				hit_done++;
				state2 = CROUCH_KICK2;
				App->audio->PlayFX(light_kick_fx);
			}
			if (player_input2.pressing_K) {
				hit_done++;
				state2 = CROUCH_PUNCH2;
				App->audio->PlayFX(light_attack_fx);
			}
		}
		if (state2 == CROUCH_UP2)
		{
			if (current_animation->Finished()) {
				state2 = IDLE2;
				crouch_up2.Reset();
			}
		}
		if (state2 == TWISTER2)
		{
			if (current_animation->Finished())
			{
				hit_done++;
				state2 = IDLE2;
				twister2.Reset();
				are_particles_created2 = false;
			}
		}
		if (state2 == CROUCH_KICK2)
		{
			if (current_animation->Finished()) {
				state2 = IDLE2;
				crouch_kick2.Reset();
			}
		}
		if (state2 == CROUCH_PUNCH2) {
			if (current_animation->Finished()) {
				state2 = IDLE2;
				crouch_punch2.Reset();
			}
		}
		if (state2 == HIT2) {
			if (position.y <= initial_position.y)
			{
				position.y++;
				if (flip == SDL_FLIP_HORIZONTAL)
				{
					position.x += speed;
				}
				else
				{
					position.x -= speed;
				}
			}
			else if ((current_animation->Finished())&&(position.y == initial_position.y+1)) {
				state2 = IDLE2;
				hit2.Reset();
			}
		}
		if ((player_input2.pressing_F5)) {
			god = !god;
		}

		if ((state2 != PUNCH2) && (state2 != KICK2) && (state2 != CROUCH_KICK2) && (state2 != CROUCH_PUNCH2) && (collider_player_2_attack != nullptr))
		{
			collider_player_2_attack->to_delete = true;
			collider_player_2_attack = nullptr;
		}
		if (state2 == WIN2)
		{
			if (current_animation->Finished())
			{
				state2 = IDLE2;
				win2.Reset();
			}
		}
		if (state2 == SPECIAL_ATTACK_2)
		{
			if (current_animation->Finished())
			{
				specialattack2.Reset();
				are_particles_created2 = false;
				state2 = IDLE2;
			}
		}
		if (state2 == EN_GARDE2)
		{
			if (current_animation->Finished())
			{
				state2 = IDLE2;
				en_garde2.Reset();
			}
		}
	}

	return UPDATE_CONTINUE;
}

update_status ModulePlayer2::Update()
{
	lposition = position;
	if (!App->is_paused) {
		switch (state2)
		{
		case IDLE2:
			current_animation = &idle2;
			position.y = lposition.y;
			shadow_x = position.x;
			//haohmaru
			/*
			if (flip != SDL_FLIP_HORIZONTAL) {
				collider_player_2_up->SetPos(position.x + 15, position.y - 80);
				collider_player_2_up->SetSize(30, 35);

				collider_player_2_down->SetPos(position.x + 10, position.y - 45);
				collider_player_2_down->SetSize(40, 45);
				shadow_x = position.x;
			}
			else {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x - 10, position.y - 80);
					collider_player_2_up->SetSize(30, 35);
				}
				if (collider_player_2_down != nullptr)
				{
					collider_player_2_down->SetPos(position.x - 15, position.y - 45);
					collider_player_2_down->SetSize(40, 45);
				}
			}
			break;
			*/
			if (flip != SDL_FLIP_HORIZONTAL) {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x + 43, position.y - 80);
					collider_player_2_up->SetSize(38, 35);
				}
				if (collider_player_2_down != nullptr)
				{
					collider_player_2_down->SetPos(position.x + 30, position.y - 45);
					collider_player_2_down->SetSize(60, 45);
				}

				shadow_x = position.x;
			}
			else {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x - 22, position.y - 80);
					collider_player_2_up->SetSize(35, 35);
				}
				if (collider_player_2_down != nullptr)
				{
					collider_player_2_down->SetPos(position.x - 30, position.y - 45);
					collider_player_2_down->SetSize(60, 45);
				}
			}
			break;
		case FORWARD2:
			current_animation = &forward2;
			position.x -= speed;
			shadow_x = position.x;
			//haohmaru
			/*
			if (flip != SDL_FLIP_HORIZONTAL) {
			collider_player_2_up->SetPos(position.x + 15, position.y - 85);
			collider_player_2_up->SetSize(30, 40);

			collider_player_2_down->SetPos(position.x + 10, position.y - 45);
			collider_player_2_down->SetSize(35, 45);
			}
			else {
			if (collider_player_2_up != nullptr)
			{
			collider_player_2_up->SetPos(position.x - 10, position.y - 85);
			collider_player_2_up->SetSize(30, 40);
			}
			if (collider_player_2_down != nullptr)
			{
			collider_player_2_down->SetPos(position.x - 15, position.y - 45);
			collider_player_2_down->SetSize(35, 45);
			}
			}
			break;
			*/
			if (flip != SDL_FLIP_HORIZONTAL) {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x + 30, position.y - 85);
					collider_player_2_up->SetSize(40, 40);
				}
				if (collider_player_2_down != nullptr)
				{
					collider_player_2_down->SetPos(position.x + 25, position.y - 45);
					collider_player_2_down->SetSize(55, 45);
				}
			}
			else {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x - 15, position.y - 85);
					collider_player_2_up->SetSize(30, 40);
				}
				if (collider_player_2_down != nullptr)
				{
					collider_player_2_down->SetPos(position.x - 25, position.y - 45);
					collider_player_2_down->SetSize(50, 45);
				}
			}
			break;
		case BACKWARD2:
			current_animation = &backward2;
			shadow_x = position.x;
			//haohmaru
			/*
			if (flip != SDL_FLIP_HORIZONTAL) {
			collider_player_2_up->SetPos(position.x + 25, position.y - 85);
			collider_player_2_up->SetSize(35, 40);

			collider_player_2_down->SetPos(position.x + 20, position.y - 45);
			collider_player_2_down->SetSize(50, 45);
			shadow_x = position.x;
			}
			else {
			if (collider_player_2_up != nullptr)
			{
			collider_player_2_up->SetPos(position.x - 25, position.y - 85);
			collider_player_2_up->SetSize(35, 40);
			}
			if (collider_player_2_down != nullptr) {
			collider_player_2_down->SetPos(position.x - 30, position.y - 45);
			collider_player_2_down->SetSize(50, 45);
			}
			}
			position.x += speed;
			break;
			*/
			if (flip != SDL_FLIP_HORIZONTAL) {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x + 25, position.y - 85);
					collider_player_2_up->SetSize(40, 40);
				}
				if (collider_player_2_down != nullptr) {
					collider_player_2_down->SetPos(position.x + 20, position.y - 45);
					collider_player_2_down->SetSize(50, 45);
				}

				shadow_x = position.x;
			}
			else {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x - 15, position.y - 85);
					collider_player_2_up->SetSize(35, 40);
				}
				if (collider_player_2_down != nullptr) {
					collider_player_2_down->SetPos(position.x - 20, position.y - 45);
					collider_player_2_down->SetSize(50, 45);
				}
			}
			position.x += speed;
			break;

		case CROUCH_DOWN2:
			current_animation = &crouch_down2;
			shadow_x = position.x - 5;
			//haohmaru
			/*
			if (flip != SDL_FLIP_HORIZONTAL) {
			collider_player_2_up->SetPos(position.x + 20, position.y - 65);
			collider_player_2_up->SetSize(35, 35);

			collider_player_2_down->SetPos(position.x + 10, position.y - 30);
			collider_player_2_down->SetSize(50, 30);

			collider_player_2_up->SetPos(position.x + 45, position.y - 65);
			collider_player_2_up->SetSize(35, 35);

			collider_player_2_down->SetPos(position.x + 30, position.y - 30);
			collider_player_2_down->SetSize(50, 30);
			shadow_x = position.x + shadow_w / 3;
			}
			else {
			if (collider_player_2_up != nullptr)
			{
			collider_player_2_up->SetPos(position.x - 15, position.y - 80);
			collider_player_2_up->SetSize(35, 50);
			}
			if (collider_player_2_down != nullptr)
			{
			collider_player_2_down->SetPos(position.x - 20, position.y - 30);
			collider_player_2_down->SetSize(50, 30);
			}
			if (collider_player_2_up != nullptr && current_animation->SeeCurrentFrame() > 2 && current_animation->SeeCurrentFrame() < 6) {
			collider_player_2_up->SetPos(position.x - 40, position.y - 65);
			collider_player_2_up->SetSize(35, 35);

			collider_player_2_down->SetPos(position.x - 40, position.y - 30);
			collider_player_2_down->SetSize(50, 30);
			}
			}
			break;
			*/
			if (flip != SDL_FLIP_HORIZONTAL) {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x + 40, position.y - 85);
					collider_player_2_up->SetSize(35, 55);
				}
				if (collider_player_2_down != nullptr)
				{
					collider_player_2_down->SetPos(position.x + 20, position.y - 30);
					collider_player_2_down->SetSize(70, 30);
				}
				if (collider_player_2_up != nullptr && current_animation->SeeCurrentFrame() > 2 && current_animation->SeeCurrentFrame() < 6) {
					collider_player_2_up->SetPos(position.x + 35, position.y - 75);
					collider_player_2_up->SetSize(55, 45);

					collider_player_2_down->SetPos(position.x + 30, position.y - 30);
					collider_player_2_down->SetSize(60, 30);
				}

				shadow_x = position.x + shadow_w / 3;
			}
			else {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x - 23, position.y - 80);
					collider_player_2_up->SetSize(35, 60);
				}
				if (collider_player_2_down != nullptr)
				{
					collider_player_2_down->SetPos(position.x - 40, position.y - 30);
					collider_player_2_down->SetSize(50, 30);
				}
				if (collider_player_2_up != nullptr && current_animation->SeeCurrentFrame() > 2 && current_animation->SeeCurrentFrame() < 6) {
					collider_player_2_up->SetPos(position.x - 35, position.y - 75);
					collider_player_2_up->SetSize(55, 50);

					collider_player_2_down->SetPos(position.x - 35, position.y - 30);
					collider_player_2_down->SetSize(58, 30);
				}
			}
			break;
		case CROUCH_UP2:
			current_animation = &crouch_up2;
			break;
		case CROUCH_KICK2:
			current_animation = &crouch_kick2;
			//haohmaru
			/*
			if (flip != SDL_FLIP_HORIZONTAL) {
			if (collider_player_2_up != nullptr) {
			collider_player_2_up->SetPos(position.x + 10, position.y - 55);
			collider_player_2_up->SetSize(40, 35);
			}
			if (collider_player_2_down) {
			collider_player_2_down->SetPos(position.x + 5, position.y - 20);
			collider_player_2_down->SetSize(75, 25);
			}

			if (collider_player_2_attack == nullptr) {
			collider_player_2_attack = App->collision->AddCollider({ position.x + 15, position.y - 10,100,20 }, COLLIDER_PLAYER_2_ATTACK, (Module*)App->player);
			collider_player_2_attack->SetSize(85, 15);
			shadow_x = position.x;
			}
			}
			else {
			if (collider_player_2_up != nullptr)
			{
			collider_player_2_up->SetPos(position.x - 10, position.y - 55);
			collider_player_2_up->SetSize(40, 35);
			}
			if (collider_player_2_down != nullptr)
			{
			collider_player_2_down->SetPos(position.x - 30, position.y - 20);
			collider_player_2_down->SetSize(75, 25);
			}
			if (collider_player_2_attack == nullptr) {
			collider_player_2_attack = App->collision->AddCollider({ position.x - 50, position.y - 10,100,20 }, COLLIDER_PLAYER_2_ATTACK, (Module*)App->player);
			collider_player_2_attack->SetSize(85, 15);
			}
			}
			break;
			*/
			if (flip != SDL_FLIP_HORIZONTAL) {
				


			}
			else {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x - 10, position.y - 55);
					collider_player_2_up->SetSize(40, 35);
				}
				if (collider_player_2_down != nullptr)
				{
					collider_player_2_down->SetPos(position.x - 30, position.y - 20);
					collider_player_2_down->SetSize(75, 25);
				}
				if (collider_player_2_attack == nullptr) {
					collider_player_2_attack = App->collision->AddCollider({ position.x - 50, position.y - 10,100,20 }, COLLIDER_PLAYER_2_ATTACK, (Module*)App->player);
					collider_player_2_attack->SetSize(85, 15);
				}
			}
			break;
		case CROUCH_PUNCH2:
			current_animation = &crouch_punch2;
			shadow_x = position.x;
			//haohmaru
			/*
			if (flip != SDL_FLIP_HORIZONTAL) {
			collider_player_2_up->SetPos(position.x + 55, position.y - 45);
			collider_player_2_up->SetSize(38, 35);

			collider_player_2_down->SetPos(position.x + 15, position.y - 15);
			collider_player_2_down->SetSize(60, 15);

			if (collider_player_2_attack == nullptr)
			{
			collider_player_2_attack = App->collision->AddCollider({ position.x + 55, position.y - 15,80,20 }, COLLIDER_PLAYER_2_ATTACK, (Module*)App->player);
			}
			shadow_x = position.x + shadow_w / 3;
			}
			else {
			if (collider_player_2_up != nullptr)
			{
			collider_player_2_up->SetPos(position.x - 40, position.y - 65);
			collider_player_2_up->SetSize(35, 35);
			}
			if (collider_player_2_down != nullptr)
			{
			collider_player_2_down->SetPos(position.x - 30, position.y - 30);
			collider_player_2_down->SetSize(100, 30);
			}
			if (collider_player_2_attack == nullptr)
			{
			collider_player_2_attack = App->collision->AddCollider({ position.x - 70, position.y - 15,80,20 }, COLLIDER_PLAYER_2_ATTACK, (Module*)App->player);
			}
			}
			break;
			*/
			if (flip != SDL_FLIP_HORIZONTAL) {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x + 35, position.y - 80);
					collider_player_2_up->SetSize(35, 50);
				}
				if (collider_player_2_down != nullptr)
				{
					collider_player_2_down->SetPos(position.x + 5, position.y - 30);
					collider_player_2_down->SetSize(70, 35);
				}
				if (collider_player_2_attack == nullptr)
				{
					collider_player_2_attack = App->collision->AddCollider({ position.x + 55, position.y - 50,80,40 }, COLLIDER_PLAYER_2_ATTACK, (Module*)App->player);
				}

				shadow_x = position.x + shadow_w / 3;
			}
			else {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x - 20, position.y - 80);
					collider_player_2_up->SetSize(35, 50);
				}
				if (collider_player_2_down != nullptr)
				{
					collider_player_2_down->SetPos(position.x - 25, position.y - 30);
					collider_player_2_down->SetSize(70, 35);
				}
				if (collider_player_2_attack == nullptr)
				{
					collider_player_2_attack = App->collision->AddCollider({ position.x - 50, position.y - 50,80,40 }, COLLIDER_PLAYER_2_ATTACK, (Module*)App->player);
				}
			}
			break;
		case JUMP_NEUTRAL2:
			current_animation = &jump_neutral2;
			position.y -= speed * 2 * mult;

			if (position.y <= 100) {
				mult = -1;
			}
			else if (position.y == initial_position.y)
			{

				mult = 1;
				jump_neutral2.Reset();
				state2 = IDLE2;
				App->render->StartCameraShake(400, 3);
			}
			else if (position.y > initial_position.y)
			{
				position.y = initial_position.y;
				mult = 1;
			}
			//haohmaru
			/*
			if (flip != SDL_FLIP_HORIZONTAL) {
			collider_player_2_up->SetPos(position.x, position.y - 90);
			collider_player_2_up->SetSize(35, 35);

			collider_player_2_down->SetPos(position.x, position.y - 50);
			collider_player_2_down->SetSize(50, 30);
			shadow_x = position.x;
			}
			else {
			if (collider_player_2_up != nullptr)
			{
			collider_player_2_up->SetPos(position.x, position.y - 90);
			collider_player_2_up->SetSize(35, 35);
			}
			if (collider_player_2_down != nullptr)
			{
			collider_player_2_down->SetPos(position.x - 12, position.y - 50);
			collider_player_2_down->SetSize(50, 30);
			}
			}
			break;
			*/
			if (flip != SDL_FLIP_HORIZONTAL) {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x + 30, position.y - 90);
					collider_player_2_up->SetSize(45, 35);
				}
				if (collider_player_2_down != nullptr)
				{
					collider_player_2_down->SetPos(position.x + 25, position.y - 50);
					collider_player_2_down->SetSize(55, 35);
				}

				shadow_x = position.x;
			}
			else {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x-30, position.y - 100);
					collider_player_2_up->SetSize(35, 50);
				}
				if (collider_player_2_down != nullptr)
				{
					collider_player_2_down->SetPos(position.x - 40, position.y - 50);
					collider_player_2_down->SetSize(50, 30);
				}
			}
			break;
		case JUMP_FORWARD2:
			current_animation = &jump_forward2;

			position.y -= speed * 1.75 * mult;
			position.x -= 1.25*speed;

			if (position.y <= 100) {
				mult = -1;
			}
			else if (position.y == initial_position.y)
			{
				mult = 1;
				jump_forward2.Reset();
				state2 = IDLE2;
				App->render->StartCameraShake(500,3);
			}
			else if (position.y > initial_position.y)
			{
				position.y = initial_position.y;
				mult = 1;
				jump_forward2.Reset();
				state2 = IDLE2;
				App->render->StartCameraShake(500,3);
			}
			//haohmaru
			/*
			if (flip != SDL_FLIP_HORIZONTAL) {
			collider_player_2_up->SetPos(position.x + 15, position.y - 1000);
			collider_player_2_up->SetSize(40, 50);

			collider_player_2_down->SetPos(position.x + 10, position.y - 60);
			collider_player_2_down->SetSize(30, 30);

			if (current_animation->SeeCurrentFrame() > 4)
			{
			if (collider_player_2_up != nullptr)
			{
			collider_player_2_up->SetPos(position.x + 10, position.y - 55);
			collider_player_2_up->SetSize(45, 35);
			}
			}
			}
			else {
			if (collider_player_2_up != nullptr)
			{
			collider_player_2_up->SetPos(position.x - 20, position.y - 90);
			collider_player_2_up->SetSize(40, 50);
			}
			if (collider_player_2_down != nullptr)
			{
			collider_player_2_down->SetPos(position.x, position.y - 50);
			collider_player_2_down->SetSize(30, 30);
			}
			if (current_animation->SeeCurrentFrame() > 5)
			{
			if (collider_player_2_up != nullptr)
			{
			collider_player_2_up->SetPos(position.x - 20, position.y - 45);
			collider_player_2_up->SetSize(45, 35);
			}
			}
			}
			*/
			if (flip != SDL_FLIP_HORIZONTAL) {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x + 35, position.y - 100);
					collider_player_2_up->SetSize(50, 50);
				}
				if (collider_player_2_down != nullptr)
				{
					collider_player_2_down->SetPos(position.x + 20, position.y - 50);
					collider_player_2_down->SetSize(60, 40);
				}
				if (current_animation->SeeCurrentFrame() > 1)
				{
					if (collider_player_2_up != nullptr)
					{
						collider_player_2_up->SetPos(position.x + 40, position.y - 90);
						collider_player_2_up->SetSize(60, 60);
					}
					if (collider_player_2_down != nullptr)
					{
						collider_player_2_down->SetPos(position.x + 20, position.y - 45);
						collider_player_2_down->SetSize(75, 40);
					}
				}
			}
			else {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x - 25, position.y - 90);
					collider_player_2_up->SetSize(40, 50);
				}
				if (collider_player_2_down != nullptr)
				{
					collider_player_2_down->SetPos(position.x-35, position.y - 45);
					collider_player_2_down->SetSize(50, 35);
				}
				if (current_animation->SeeCurrentFrame() > 5)
				{
					if (collider_player_2_up != nullptr)
					{
						collider_player_2_up->SetPos(position.x - 40, position.y - 75);
						collider_player_2_up->SetSize(45, 35);

						collider_player_2_down->SetPos(position.x - 35, position.y - 45);
						collider_player_2_down->SetSize(50, 35);
					}
				}
			}
			shadow_x = position.x;
			break;
		case JUMP_BACKWARD2:
			current_animation = &jump_backward2;

			position.y -= speed * 1.75 * mult;
			position.x += 1.25*speed;

			if (position.y <= 100) {
				mult = -1;
			}
			else if (position.y == initial_position.y)
			{
				mult = 1;
				jump_backward2.Reset();
				state2 = IDLE2;
				App->render->StartCameraShake(500, 3);
			}
			else if (position.y > initial_position.y)
			{
				position.y = initial_position.y;
				jump_backward2.Reset();
				state2 = IDLE2;
				App->render->StartCameraShake(400, 3);
				mult = 1;
			}
			else if (position.y > initial_position.y)
			{
				position.y = initial_position.y;
				mult = 1;
				jump_forward2.Reset();
				App->render->StartCameraShake(500, 3);
			}
			//haohmaru
			/*
			if (flip != SDL_FLIP_HORIZONTAL)
			{
			if (collider_player_2_up != nullptr)
			{
			collider_player_2_up->SetPos(position.x, position.y - 90);
			collider_player_2_up->SetSize(35, 35);
			}
			if (collider_player_2_down != nullptr)
			{
			collider_player_2_down->SetPos(position.x, position.y - 50);
			collider_player_2_down->SetSize(40, 30);
			}
			if (current_animation->SeeCurrentFrame() > 4) {
			collider_player_2_up->SetPos(position.x + 20, position.y - 45);
			collider_player_2_up->SetSize(35, 35);
			}
			}
			else {
			if (collider_player_2_up != nullptr)
			{
			collider_player_2_up->SetPos(position.x, position.y - 90);
			collider_player_2_up->SetSize(35, 35);
			}
			if (collider_player_2_down != nullptr)
			{
			collider_player_2_down->SetPos(position.x, position.y - 50);
			collider_player_2_down->SetSize(40, 30);
			}
			if (current_animation->SeeCurrentFrame() > 4)
			{
			if (collider_player_2_up != nullptr)
			{
			collider_player_2_up->SetPos(position.x - 20, position.y - 45);
			collider_player_2_up->SetSize(35, 35);
			}
			}
			}
			*/
			if (flip != SDL_FLIP_HORIZONTAL)
			{
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x + 35, position.y - 100);
					collider_player_2_up->SetSize(60, 50);
				}
				if (collider_player_2_down != nullptr)
				{
					collider_player_2_down->SetPos(position.x + 20, position.y - 50);
					collider_player_2_down->SetSize(50, 40);
				}
				if (current_animation->SeeCurrentFrame() > 1)
				{
					if (collider_player_2_up != nullptr)
					{
						collider_player_2_up->SetPos(position.x + 35, position.y - 90);
						collider_player_2_up->SetSize(45, 60);
					}
					if (collider_player_2_down != nullptr)
					{
						collider_player_2_down->SetPos(position.x + 20, position.y - 45);
						collider_player_2_down->SetSize(75, 30);
					}
				}
			}
			else {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x - 25, position.y - 90);
					collider_player_2_up->SetSize(40, 50);
				}
				if (collider_player_2_down != nullptr)
				{
					collider_player_2_down->SetPos(position.x - 35, position.y - 45);
					collider_player_2_down->SetSize(50, 35);
				}
				if (current_animation->SeeCurrentFrame() > 5)
				{
					if (collider_player_2_up != nullptr)
					{
						collider_player_2_up->SetPos(position.x - 40, position.y - 75);
						collider_player_2_up->SetSize(45, 35);

						collider_player_2_down->SetPos(position.x - 35, position.y - 45);
						collider_player_2_down->SetSize(50, 35);
					}
				}
			}
			shadow_x = position.x;
			break;
			case JUMP_PUNCH2:
				current_animation = &jump_punch2;
				//Wan-Fu
				if (flip != SDL_FLIP_HORIZONTAL) {



				}
				else {
					if (collider_player_2_up != nullptr)
					{
						collider_player_2_up->SetPos(position.x - 20, position.y - 60);
						collider_player_2_up->SetSize(50, 47);
					}
					if (collider_player_2_up != nullptr)
					{
						collider_player_2_down->SetPos(position.x - 10, position.y - 10);
						collider_player_2_down->SetSize(70, 15);
					}
					if (collider_player_2_attack == nullptr)
					{
						collider_player_2_attack = App->collision->AddCollider({ position.x - 500, position.y,78,40 }, COLLIDER_PLAYER_2_ATTACK, (Module*)App->player2);
						collider_player_2_attack->SetPos(position.x - 60, position.y - 50);
						collider_player_2_attack->SetSize(67, 30);
					}
				}
				position.y -= speed * 1.75 * mult;
				position.x -= 1.25*speed*direction_x;

				if (position.y <= 100) {
					mult = -1;
				}
				else if (position.y == initial_position.y)
				{
					mult = 1;
					jump_forward2.Reset();
					state2 = IDLE2;
					App->render->StartCameraShake(500, 3);
				}
				else if (position.y > initial_position.y)
				{
					position.y = initial_position.y;
					mult = 1;
					jump_forward2.Reset();
					state2 = IDLE2;
					App->render->StartCameraShake(500, 3);
				}
				shadow_x = position.x;
				break;
			case JUMP_KICK2:
				current_animation = &jump_kick2;
				//Wan-Fu
				if (flip != SDL_FLIP_HORIZONTAL) {
					if (collider_player_2_up != nullptr)
					{
						collider_player_2_up->SetPos(position.x + 40, position.y - 100);
						collider_player_2_up->SetSize(40, 75);
					}
					if (collider_player_2_down != nullptr)
					{
						collider_player_2_down->SetPos(position.x + 40, position.y - 100);
						collider_player_2_down->SetSize(1, 1);
					}
					if (collider_player_2_attack == nullptr)
					{
						collider_player_2_attack = App->collision->AddCollider({ position.x, position.y,80,40 }, COLLIDER_PLAYER_2_ATTACK, (Module*)App->player);
						collider_player_2_attack->SetPos(position.x + 50, position.y - 70);
						collider_player_2_attack->SetSize(50, 50);
					}
				}
				else {
					if (collider_player_2_up != nullptr)
					{
						collider_player_2_up->SetPos(position.x - 25, position.y - 100);
						collider_player_2_up->SetSize(40, 75);
					}
					if (collider_player_2_down != nullptr)
					{
						collider_player_2_down->SetPos(position.x - 25, position.y - 100);
						collider_player_2_down->SetSize(1, 1);
					}
					if (collider_player_2_attack == nullptr)
					{
						collider_player_2_attack = App->collision->AddCollider({ position.x, position.y,80,40 }, COLLIDER_PLAYER_2_ATTACK, (Module*)App->player);
						collider_player_2_attack->SetPos(position.x - 50, position.y - 70);
						collider_player_2_attack->SetSize(45, 50);
					}
				}
				position.y -= speed * 1.75 * mult;
				position.x -= 1.25*speed*direction_x;

				if (position.y <= 100) {
					mult = -1;
				}
				else if (position.y == initial_position.y)
				{
					mult = 1;
					jump_forward2.Reset();
					state2 = IDLE2;
					App->render->StartCameraShake(500, 3);
				}
				else if (position.y > initial_position.y)
				{
					position.y = initial_position.y;
					mult = 1;
					jump_forward2.Reset();
					state2 = IDLE2;
					App->render->StartCameraShake(500, 3);
				}
				shadow_x = position.x;
				break;
		case PUNCH2:
			current_animation = &punch2;
			//haohmaru
			/*
			if (flip != SDL_FLIP_HORIZONTAL) {
			if (collider_player_2_up != nullptr)
			{
			collider_player_2_up->SetPos(position.x + 20, position.y - 60);
			collider_player_2_up->SetSize(50, 47);
			}
			if (collider_player_2_down != nullptr)
			{
			collider_player_2_down->SetPos(position.x, position.y - 10);
			collider_player_2_down->SetSize(70, 15);
			}
			if (collider_player_2_attack == nullptr)
			{
			collider_player_2_attack = App->collision->AddCollider({ position.x, position.y,78,40 }, COLLIDER_PLAYER_2_ATTACK, (Module*)App->player2);
			collider_player_2_attack->SetPos(position.x + 60, position.y - 50);
			collider_player_2_attack->SetSize(67, 30);
			}
			}
			else {
			if (collider_player_2_up != nullptr)
			{
			collider_player_2_up->SetPos(position.x - 20, position.y - 60);
			collider_player_2_up->SetSize(50, 47);
			}
			if (collider_player_2_up != nullptr)
			{
			collider_player_2_down->SetPos(position.x - 10, position.y - 10);
			collider_player_2_down->SetSize(70, 15);
			}
			if (collider_player_2_attack == nullptr)
			{
			collider_player_2_attack = App->collision->AddCollider({ position.x - 500, position.y,78,40 }, COLLIDER_PLAYER_2_ATTACK, (Module*)App->player2);
			collider_player_2_attack->SetPos(position.x - 60, position.y - 50);
			collider_player_2_attack->SetSize(67, 30);
			}
			}
			*/
			if (flip != SDL_FLIP_HORIZONTAL) {
				



			}
			else {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x - 20, position.y - 60);
					collider_player_2_up->SetSize(50, 47);
				}
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_down->SetPos(position.x - 10, position.y - 10);
					collider_player_2_down->SetSize(70, 15);
				}
				if (collider_player_2_attack == nullptr)
				{
					collider_player_2_attack = App->collision->AddCollider({ position.x - 500, position.y,78,40 }, COLLIDER_PLAYER_2_ATTACK, (Module*)App->player2);
					collider_player_2_attack->SetPos(position.x - 60, position.y - 50);
					collider_player_2_attack->SetSize(67, 30);
				}
			}
			break;
		case KICK2:
			current_animation = &kick2;
			//haohmaru
			/*
			if (flip != SDL_FLIP_HORIZONTAL) {
			if (collider_player_2_up != nullptr) {
			collider_player_2_up->SetPos(position.x + 10, position.y - 70);
			collider_player_2_up->SetSize(50, 30);
			}
			if (collider_player_2_down != nullptr) {
			collider_player_2_down->SetPos(position.x + 20, position.y - 80);
			collider_player_2_down->SetSize(25, 85);
			}
			if (collider_player_2_attack == nullptr)
			{
			collider_player_2_attack = App->collision->AddCollider({ position.x, position.y,80,40 }, COLLIDER_PLAYER_2_ATTACK, (Module*)App->player);
			collider_player_2_attack->SetPos(position.x + 30, position.y - 35);
			collider_player_2_attack->SetSize(56, 30);
			}
			}
			else {
			if (collider_player_2_up != nullptr)
			{
			collider_player_2_up->SetPos(position.x - 20, position.y - 70);
			collider_player_2_up->SetSize(50, 30);
			}
			if (collider_player_2_down != nullptr)
			{
			collider_player_2_down->SetPos(position.x, position.y - 80);
			collider_player_2_down->SetSize(25, 85);
			}
			if (collider_player_2_attack == nullptr)
			{
			collider_player_2_attack = App->collision->AddCollider({ position.x - 43, position.y - 35,80,40 }, COLLIDER_PLAYER_2_ATTACK, (Module*)App->player2);
			collider_player_2_attack->SetSize(56, 30);
			}
			}
			break;
			*/
			if (flip != SDL_FLIP_HORIZONTAL) {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x + 40, position.y - 100);
					collider_player_2_up->SetSize(40, 75);
				}
				if (collider_player_2_down != nullptr)
				{
					collider_player_2_down->SetPos(position.x + 40, position.y - 100);
					collider_player_2_down->SetSize(1, 1);
				}
				if (collider_player_2_attack == nullptr)
				{
					collider_player_2_attack = App->collision->AddCollider({ position.x, position.y,80,40 }, COLLIDER_PLAYER_2_ATTACK, (Module*)App->player);
					collider_player_2_attack->SetPos(position.x + 50, position.y - 70);
					collider_player_2_attack->SetSize(50, 50);
				}
			}
			else {
				if(collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x - 25, position.y - 100);
					collider_player_2_up->SetSize(40, 75);
				}
				if (collider_player_2_down != nullptr)
				{
					collider_player_2_down->SetPos(position.x - 25, position.y - 100);
					collider_player_2_down->SetSize(1, 1);
				}
				if (collider_player_2_attack == nullptr)
				{
					collider_player_2_attack = App->collision->AddCollider({ position.x, position.y,80,40 }, COLLIDER_PLAYER_2_ATTACK, (Module*)App->player);
					collider_player_2_attack->SetPos(position.x - 50, position.y - 70);
					collider_player_2_attack->SetSize(45, 50);
				}
			}
			break;
		case TWISTER2:
			current_animation = &twister2;
			//haohmaru
			/*
			if (flip != SDL_FLIP_HORIZONTAL) {
			if (collider_player_2_up != nullptr)
			{
			collider_player_2_up->SetPos(position.x + 15, position.y - 75);
			collider_player_2_up->SetSize(40, 45);
			}
			if (collider_player_2_down != nullptr)
			{
			collider_player_2_down->SetPos(position.x + 5, position.y - 35);
			collider_player_2_down->SetSize(60, 40);
			}
			if (current_animation->SeeCurrentFrame() == 10 && !is_tornado_created2) {
			Particle* p = App->particles->AddParticle(App->particles->tornado, position.x, position.y - 205, COLLIDER_PLAYER_2_PARTICLES);
			is_tornado_created2 = true;
			p->speed = { -2,0 };
			}
			}
			else {
			if (collider_player_2_up != nullptr)
			{
			collider_player_2_up->SetPos(position.x - 20, position.y - 75);
			collider_player_2_up->SetSize(40, 45);
			}
			if (collider_player_2_down != nullptr)
			{
			collider_player_2_down->SetPos(position.x - 30, position.y - 35);
			collider_player_2_down->SetSize(60, 40);
			}
			if (current_animation->SeeCurrentFrame() == 10 && !is_tornado_created2) {
			App->particles->AddParticle(App->particles->tornado, position.x, position.y - 205, COLLIDER_PLAYER_2_PARTICLES);
			is_tornado_created2 = true;
			}
			}
			break;
			*/
			if (flip != SDL_FLIP_HORIZONTAL) {
				


			}
			else {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x - 20, position.y - 75);
					collider_player_2_up->SetSize(40, 45);
				}
				if (collider_player_2_down != nullptr)
				{
					collider_player_2_down->SetPos(position.x - 30, position.y - 35);
					collider_player_2_down->SetSize(60, 40);
				}
				if (current_animation->SeeCurrentFrame() == 10 && !are_particles_created2) {
					App->particles->AddParticle(App->particles->tornado, position.x, position.y - 205, COLLIDER_PLAYER_2_PARTICLES);
					are_particles_created2 = true;
				}
			}
			break;
		case SPECIAL_ATTACK_2:
			//current_animation = &twister;
			current_animation = &specialattack2;
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
			//Wan-Fu
			if (flip == SDL_FLIP_HORIZONTAL) {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x - 23, position.y - 90);
					collider_player_2_up->SetSize(40, 45);
				}
				if (collider_player_2_down != nullptr)
				{
					collider_player_2_down->SetPos(position.x - 28, position.y - 45);
					collider_player_2_down->SetSize(60, 30);
				}
				if (current_animation->SeeCurrentFrame() == 14 && !are_particles_created2) {
					App->particles->AddParticle(App->particles->fire_sword, position.x - 50, position.y, COLLIDER_PLAYER_2_PARTICLES);
					are_particles_created2 = true;
				}
				position.x += 1 * speed;
			}
			else {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x + 15, position.y - 90);
					collider_player_2_up->SetSize(45, 45);
				}
				if (collider_player_2_down != nullptr)
				{
					collider_player_2_down->SetPos(position.x + 5, position.y - 50);
					collider_player_2_down->SetSize(60, 30);
				}
				if (current_animation->SeeCurrentFrame() == 14 && !are_particles_created2) {
					App->particles->AddParticle(App->particles->fire_sword, position.x + 50, position.y, COLLIDER_PLAYER_2_PARTICLES);
					are_particles_created2 = true;
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
				specialattack2.Reset();
				state2 = IDLE2;
				are_particles_created2 = false;
			}
			else if (position.y > initial_position.y)
			{
				position.y = initial_position.y;
				specialattack2.Reset();
				state2 = IDLE2;
				are_particles_created2 = false;
				mult = 1;
			}
			else if (position.y > initial_position.y)
			{
				position.y = initial_position.y;
				mult = 1;
			}
			break;
		case DEATH2:
			current_animation = &die2;
			position.y = initial_position.y + 10;
			break;
		case EN_GARDE2:
			current_animation = &en_garde2;
			if (flip != SDL_FLIP_HORIZONTAL) {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x + 43, position.y - 80);
					collider_player_2_up->SetSize(38, 35);
				}
				if (collider_player_2_down != nullptr)
				{
					collider_player_2_down->SetPos(position.x + 30, position.y - 45);
					collider_player_2_down->SetSize(60, 45);
				}

				shadow_x = position.x;
			}
			else {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x - 22, position.y - 80);
					collider_player_2_up->SetSize(35, 35);
				}
				if (collider_player_2_down != nullptr)
				{
					collider_player_2_down->SetPos(position.x - 30, position.y - 45);
					collider_player_2_down->SetSize(60, 45);
				}
			}
			break;
		case WIN2:
			current_animation = &win2;
			break;
		case HIT2:
			current_animation = &hit2;
			shadow_x = position.x;
			//haohmaru
			/*
			if (flip != SDL_FLIP_HORIZONTAL) {
			collider_player_2_up->SetPos(position.x + 15, position.y - 85);
			collider_player_2_down->SetPos(position.x + 20, position.y - 45);
			}
			else {
			if (collider_player_2_up != nullptr)
			{
			collider_player_2_up->SetPos(position.x - 15, position.y - 85);
			}
			if (collider_player_2_down != nullptr)
			{
			collider_player_2_down->SetPos(position.x - 30, position.y - 45);
			}
			}
			break;
			}
			*/
			if (flip != SDL_FLIP_HORIZONTAL) {
				


			}
			else {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x - 15, position.y - 85);
				}
				if (collider_player_2_down != nullptr)
				{
					collider_player_2_down->SetPos(position.x - 30, position.y - 45);
				}
			}
			break;
		}
		/*if (App->player->position.y < position.y -30)
		{
			if (App->player->position.x +10 > position.x)
			{
				position.x += speed;
			}
			else //if (App->player->position.x > position.x)
			{
				position.x -= speed;
			}
		}*/
		if ((position.y < initial_position.y) && ((state2 != JUMP_BACKWARD2) && (state2 != JUMP_NEUTRAL2) && (state2 != JUMP_FORWARD2) && (state2 != HIT2) && (state2 != SPECIAL_ATTACK_2) && (state2 != JUMP_PUNCH2) && (state2 != JUMP_KICK2)))
		{
			state2 = JUMP_NEUTRAL2;
		}
		/*
		if (App->player->position.y < position.y - 40) {
			if (App->player->position.x + 10 < position.x)
			{
				position.x = lposition.x - speed;
			}
			else
			{
				position.x = lposition.x + speed;
			}
		}*/
	}

	//Draw everything
	SDL_Rect r = current_animation->GetCurrentFrame();
	//SDL_Rect shadow = { 1348, 2627, 70, 17 };
	SDL_Rect shadow = { 1181,138,91,17 };

	if (position.x < App->player->position.x) {
		flip = SDL_FLIP_NONE;
	}
	else {
		flip = SDL_FLIP_HORIZONTAL;
	}
	if (flip == SDL_FLIP_HORIZONTAL) {
		if (shadow_blit) {
			App->render->Blit(App->player->player_textures, shadow_x - shadow.w / 2, initial_position.y - 10, &shadow, flip);
			shadow_blit = false;
		}
		else {
			shadow_blit = true;
		}
		App->render->Blit(App->player->player_textures, position.x - current_animation->GetCurrentRect().w / 2, position.y - r.h, &r, flip);
	}
	else {
		if (shadow_blit) {
			App->render->Blit(App->player->player_textures, shadow_x, initial_position.y - 10, &shadow, flip);
			shadow_blit = false;
		}
		else {
			shadow_blit = true;
		}
		App->render->Blit(App->player->player_textures, position.x, position.y - r.h, &r, flip);

	}
	return UPDATE_CONTINUE;
}

bool ModulePlayer2::CleanUp() {
	LOG("Unloading player");

	App->audio->UnLoadFx(light_attack_fx);
	App->audio->UnLoadFx(light_kick_fx);
	App->audio->UnLoadFx(twister_fx);
	App->audio->UnLoadFx(hit_fx);
	App->collision->CleanUp();
	collider_player_2_up = nullptr;
	collider_player_2_mid = nullptr;
	collider_player_2_down = nullptr;
	collider_player_2_attack = nullptr;
	App->ui->Disable();
	return true;
}


void ModulePlayer2::OnCollision(Collider* c1, Collider* c2) {
	
	if ((state2 != DEATH2)&&(!App->is_paused)) {
		switch (c2->type)
		{
		case COLLIDER_WALL_LEFT:
			if (!player_input2.pressing_right && state2 != DEATH2 && state2 != WIN2)
				position.x += speed;

			break;
		case COLLIDER_WALL_RIGHT:
			if (!player_input2.pressing_left && state2 != DEATH2 && state2 != WIN2)
				position.x -= speed;
			break;
		case COLLIDER_PLAYER:
			if (((state2 != KICK2) && (state2 != PUNCH2) && (state2 != CROUCH_KICK2) && (state2 != CROUCH_PUNCH2)) && (state2 != TWISTER2) && (state2 != DEATH2) && (state2 != WIN2))
			{
			//	if (App->player->position.y > position.y - 1)
			//	{
					if (App->player->position.x > position.x)
					{
						position.x = lposition.x - speed;
					}
					else
					{
						position.x = lposition.x + speed;
					}
				}
		//	}
			break;
		case COLLIDER_PLAYER_1_ATTACK:
			if (!App->player->collider_player_attack->to_delete && !god) {
				App->player->hit_percent++;
				switch (App->player->state)
				{
				case States::KICK:
					App->ui->player1_point += 50;
					break;
				case States::PUNCH:
					App->ui->player1_point += 50;
					break;
				case States::CROUCH_PUNCH:
					App->ui->player1_point += 200;
					break;
				case States::CROUCH_KICK:
					App->ui->player1_point += 200;
					break;
				case States::TWISTER:
					App->ui->player1_point += 400;
					break;
				default:
					break;
				}
				App->audio->PlayFX(hit_fx);
				life -= 10;
				state2 = HIT2;
				App->player->collider_player_attack->to_delete = true;
				if ((position.x < App->player->position.x) && (position.x > App->render->left->rect.x + 60))
				{
					position.x -= 10;
				}
				else if ((position.x > App->player->position.x) && (position.x > App->render->right->rect.x))
				{
					position.x += 10;
				}
			}
			App->render->StartCameraShake(400, 3);
			App->render->StartSlowdown(800, 30);
			break;
		case COLLIDER_PLAYER_PARTICLES:
			App->audio->PlayFX(hit_fx);
			life -= 20;
			state2 = HIT2;
			position.x += 5;
			App->render->StartCameraShake(400, 3);
			App->render->StartSlowdown(800, 30);
			break;
		default:
			break;
		}
	}

}

void ModulePlayer2::BlockControls(bool block)
{
	controls = !block;
}