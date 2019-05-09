#include "ModuleHaohmaru.h"

ModuleHaohmaru::ModuleHaohmaru() {
	
	//animations 
	{
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

			//in.PushBack({49, 2072, 76, 177}, 0.2f);
			//win.PushBack({146, 2072, 76, 177}, 0.2f);
			//win.PushBack({250, 2079, 90, 170}, 0.2f);
			//win.PushBack({340, 2071, 90, 178}, 0.2f);
			//win.PushBack({440, 2040, 76, 209}, 0.2f);
			//win.PushBack({538, 2040, 76, 209 }, 0.2f);
			//win.PushBack({631, 2040, 74, 209 }, 0.2f);
			//win.PushBack({731 , 2040, 74, 209 }, 0.2f);
			//win.PushBack({827, 2040, 74, 209 }, 0.2f);
			//win.PushBack({923, 2040, 74, 209 }, 0.2f);
			//win.PushBack({1025, 2131, 74, 118}, 0.2f);
			//win.PushBack({1125, 2146, 49, 102}, 0.2f);
			//win.PushBack({1182, 2143, 96, 106}, 0.2f);
			//win.PushBack({1288, 2143, 96, 106}, 0.2f);
			//win.PushBack({1409, 2144, 96, 106}, 0.2f);
			//win.PushBack({1515, 2144, 96, 106}, 0.2f);
			//win.PushBack({1614, 2143, 96, 106}, 0.2f);
			//win.PushBack({1723, 2144, 96, 106}, 0.2f);
			//win.PushBack({1838, 2143, 97, 106}, 0.2f);
			//win.PushBack({28, 2359, 96, 106}, 0.2f);
			//win.PushBack({140, 2359, 96, 106}, 0.2f);
			//win.PushBack({260, 2359, 98, 106}, 0.2f);
			//win.PushBack({380, 2359, 96, 106}, 0.2f);
			//win.PushBack({482, 2359, 96, 106}, 0.2f);
			//win.PushBack({1614, 2143, 96, 106}, 0.2f);
			//win.PushBack({678, 2359, 96, 106}, 0.2f);
			//win.PushBack({803, 2256, 98, 209}, 0.2f);
			//win.PushBack({910, 2256, 98, 209}, 0.2f);
			//win.PushBack({1001, 2256, 96, 209}, 0.2f);
			//win.PushBack({1100, 2256, 96, 209}, 0.2f);
			//win.PushBack({1289, 2256, 96, 209}, 0.2f);
			//win.PushBack({1409, 2256, 100, 209}, 0.2f);
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
			win.loop = false;
		}
	}

}
