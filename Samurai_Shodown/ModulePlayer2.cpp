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
#include "ModuleJudge.h"

ModulePlayer2::ModulePlayer2()
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
				idle2.PushBack({ 28,26,118,126 }, 0.15f); //01
				idle2.PushBack({ 150,26,118,126 }, 0.15f);
				idle2.PushBack({ 272,26,118,126 }, 0.15f);
				idle2.PushBack({ 394,26,118,126 }, 0.15f); //04
				idle2.PushBack({ 514,26,118,126 }, 0.15f);
				idle2.PushBack({ 635,26,118,126 }, 0.15f);
				idle2.PushBack({ 754,40,118,112 }, 0.15f); //07
				idle2.PushBack({ 873,40,118,112 }, 0.15f);
				idle2.PushBack({ 991,40,118,112 }, 0.15f);
				idle2.PushBack({ 394,26,118,126 }, 0.15f); //04
				idle2.PushBack({ 514,26,118,126 }, 0.15f);
				idle2.PushBack({ 635,26,118,126 }, 0.15f);
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
				crouch_punch2.PushBack({ 1046, 1082, 127, 129 }, 0.5f);
				crouch_punch2.PushBack({ 1203, 1123, 138, 88 }, 0.5f);
				crouch_punch2.PushBack({ 1340, 1123, 138, 88 }, 0.5f);
				crouch_punch2.PushBack({ 1480, 1084, 102, 126 }, 0.5f);
				crouch_punch2.PushBack({ 1593, 1084, 102, 126 }, 0.5f);
				crouch_punch2.PushBack({ 1701, 1084, 102, 126 }, 0.5f);
				crouch_punch2.loop = false;

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

			//win animation
			{
				win2.PushBack({ 40, 1711, 110, 117 }, 0.1f);
				win2.PushBack({ 181, 1711, 110, 117 }, 0.1f);
				win2.PushBack({ 332, 1711, 110, 117 }, 0.1f);
				win2.PushBack({ 479, 1711, 110, 118 }, 0.1f);
				win2.PushBack({ 620, 1711, 110, 118 }, 0.1f);
				win2.PushBack({ 759, 1711, 110, 118 }, 0.1f);
				win2.PushBack({ 896, 1711, 110, 116 }, 0.1f);
				win2.PushBack({ 1032, 1711, 110, 116 }, 0.1f);
				win2.PushBack({ 1170, 1711, 110, 116 }, 0.1f);
				win2.PushBack({ 1303, 1711, 110, 120 }, 0.1f);
				win2.PushBack({ 1433, 1711, 110, 120 }, 0.1f);
				win2.PushBack({ 1558, 1711, 110, 120 }, 0.1f);
				win2.loop = true;
			}

			//jump punch

			{
				jump_punch2.PushBack({ 820, 635, 115, 112 }, 0.3f);//1
				jump_punch2.PushBack({ 956, 635, 115, 112 }, 0.3f);
				jump_punch2.PushBack({ 1087, 635, 115, 112 }, 0.3f);
				jump_punch2.PushBack({ 1227, 619, 108, 136 }, 0.3f);
				jump_punch2.PushBack({ 1355, 619, 108, 136 }, 0.3f);
				jump_punch2.PushBack({ 1487, 619, 108, 136 }, 0.3f);
				jump_punch2.PushBack({ 1611, 621, 125, 130 }, 0.3f);
				jump_punch2.PushBack({ 1766, 619, 125, 130 }, 0.3f);
				jump_punch2.PushBack({ 1914, 619, 125, 130 }, 0.3f);
				jump_punch2.PushBack({ 1443, 764, 119, 130 }, 0.3f);
				jump_punch2.PushBack({ 1586, 764, 119, 130 }, 0.3f);
				jump_punch2.PushBack({ 1750, 764, 119, 130 }, 0.3f);
				jump_punch2.loop = false;
			}
			//jump kick
			{
				jump_kick2.PushBack({ 30, 1831, 111, 104 }, 0.3f);
				jump_kick2.PushBack({ 164, 1831, 111, 104 }, 0.3f);
				jump_kick2.PushBack({ 313, 1831, 111, 104 }, 0.3f);
				jump_kick2.PushBack({ 466, 1831, 132, 110 }, 0.3f);
				jump_kick2.PushBack({ 625, 1831, 132, 110 }, 0.3f);
				jump_kick2.PushBack({ 1271, 1831, 132, 110 }, 0.3f);
				jump_kick2.PushBack({ 790, 1827, 133, 124 }, 0.3f);
				jump_kick2.PushBack({ 949, 1827, 133, 124 }, 0.3f);
				jump_kick2.PushBack({ 1112, 1827, 133, 124 }, 0.3f);
				jump_kick2.loop = false;
			}
			
			//heavy punch
			{
				heavy_punch2.PushBack({ 34, 1948, 105, 95 }, 0.5f);
				heavy_punch2.PushBack({ 156, 1948, 105, 95 }, 0.5f);
				heavy_punch2.PushBack({ 275, 1948, 105, 95 }, 0.5f);
				heavy_punch2.PushBack({ 399, 1946, 92, 97 }, 0.5f);
				heavy_punch2.PushBack({ 515, 1946, 92, 97 }, 0.5f);
				heavy_punch2.PushBack({ 626, 1946, 92, 97 }, 0.5f);
				heavy_punch2.PushBack({ 739, 1950, 107, 93 }, 0.5f);
				heavy_punch2.PushBack({ 848, 1950, 107, 93 }, 0.5f);
				heavy_punch2.PushBack({ 958, 1950, 107, 93 }, 0.5f);
				heavy_punch2.PushBack({ 1068, 1951, 162, 92 }, 0.5f);
				heavy_punch2.PushBack({ 1230, 1951, 162, 92 }, 0.5f);
				heavy_punch2.PushBack({ 1392, 1951, 162, 92 }, 0.5f);
				heavy_punch2.PushBack({ 1552, 1946, 162, 97 }, 0.5f);
				heavy_punch2.PushBack({ 1714, 1946, 162, 97 }, 0.5f);
				heavy_punch2.PushBack({ 1879, 1946, 162, 97 }, 0.5f);
				heavy_punch2.PushBack({ 547, 1479, 162, 95 }, 0.5f);
				heavy_punch2.PushBack({ 708, 1479, 162, 95 }, 0.5f);
				heavy_punch2.PushBack({ 868, 1481, 162, 93 }, 0.5f);
				heavy_punch2.PushBack({ 1029, 1481, 162, 93 }, 0.5f);
				heavy_punch2.PushBack({ 1191, 1481, 162, 93 }, 0.5f);
				heavy_punch2.PushBack({ 34, 1948, 105, 95 }, 0.5f);
				heavy_punch2.PushBack({ 156, 1948, 105, 95 }, 0.5f);
				heavy_punch2.PushBack({ 275, 1948, 105, 95 }, 0.5f);
				heavy_punch2.loop = false;
			}

			//jump heavy punch
			{
				jump_heavy_punch2.PushBack({ 820, 635, 115, 112 }, 0.3f);//1
				jump_heavy_punch2.PushBack({ 956, 635, 115, 112 }, 0.3f);
				jump_heavy_punch2.PushBack({ 1089, 635, 115, 112 }, 0.3f);
				jump_heavy_punch2.PushBack({ 1227, 619, 108, 136 }, 0.3f);
				jump_heavy_punch2.PushBack({ 1255, 619, 108, 136 }, 0.3f);
				jump_heavy_punch2.PushBack({ 1487, 619, 108, 136 }, 0.3f);
				jump_heavy_punch2.PushBack({ 1619, 621, 125, 130 }, 0.3f);
				jump_heavy_punch2.PushBack({ 1766, 619, 125, 130 }, 0.3f);
				jump_heavy_punch2.PushBack({ 1914, 619, 125, 130 }, 0.3f);
				jump_heavy_punch2.PushBack({ 1443, 764, 119, 130 }, 0.3f);
				jump_heavy_punch2.PushBack({ 1586, 764, 119, 130 }, 0.3f);
				jump_heavy_punch2.PushBack({ 1750, 764, 119, 130 }, 0.3f);
				jump_heavy_punch2.loop = false;
			}

			//heavy kick
			{
				heavy_kick2.PushBack({ 1198, 917, 107, 111 }, 0.5f);//1
				heavy_kick2.PushBack({ 1305, 917, 107, 111 }, 0.5f);
				heavy_kick2.PushBack({ 1412, 917, 107, 111 }, 0.5f);
				heavy_kick2.PushBack({ 1536, 917, 119, 111 }, 0.5f);
				heavy_kick2.PushBack({ 1664, 917, 119, 111 }, 0.5f);
				heavy_kick2.PushBack({ 1798, 917, 119, 111 }, 0.5f);
				heavy_kick2.PushBack({ 1932, 910, 114, 117 }, 0.5f);
				heavy_kick2.PushBack({ 999, 1266, 114, 117 }, 0.5f);
				heavy_kick2.PushBack({ 1113, 1266, 114, 117 }, 0.5f);
				heavy_kick2.PushBack({ 1226, 1258, 114, 125 }, 0.5f);
				heavy_kick2.PushBack({ 1341, 1258, 114, 125 }, 0.5f);
				heavy_kick2.PushBack({ 1455, 1258, 114, 125 }, 0.5f);
				heavy_kick2.PushBack({ 1536, 917, 119, 111 }, 0.5f);
				heavy_kick2.PushBack({ 1664, 917, 119, 111 }, 0.5f);
				heavy_kick2.PushBack({ 1798, 917, 119, 111 }, 0.5f);
				heavy_kick2.PushBack({ 1305, 917, 107, 111 }, 0.5f);
				heavy_kick2.PushBack({ 1412, 917, 107, 111 }, 0.5f);
				heavy_kick2.loop = false;
			}

			//jump heavy kick
			/*{
				jump_heavy_kick.PushBack({ 30, 1831, 111, 104 }, 0.3f);
				jump_heavy_kick.PushBack({ 164, 1831, 111, 104 }, 0.3f);
				jump_heavy_kick.PushBack({ 313, 1831, 111, 104 }, 0.3f);
				jump_heavy_kick.PushBack({ 466, 1831, 132, 110 }, 0.3f);
				jump_heavy_kick.PushBack({ 625, 1831, 132, 110 }, 0.3f);
				jump_heavy_kick.PushBack({ 1271, 1831, 132, 110 }, 0.3f);
				jump_heavy_kick.PushBack({ 790, 1831, 133, 125 }, 0.3f);
				jump_heavy_kick.PushBack({ 949, 1831, 133, 125 }, 0.3f);
				jump_heavy_kick.PushBack({ 1112, 1831, 133, 125 }, 0.3f);
				jump_heavy_kick.loop = false;
			}*/
			//die
			{
				die2.PushBack({ 45,746,127,156 }, 0.1f);//1
				die2.PushBack({ 172,746,127,156 }, 0.1f);
				die2.PushBack({ 300,746,127,156 }, 0.1f);
				die2.PushBack({ 433,779,131,123 }, 0.1f);//4
				die2.PushBack({ 566,779,131,123 }, 0.1f);
				die2.PushBack({ 695,779,131,123 }, 0.1f);
				die2.PushBack({ 824,826,120,76 }, 0.1f);//1
				die2.PushBack({ 945,826,120,76 }, 0.1f);
				die2.PushBack({ 1068,826,120,76 }, 0.1f);
				die2.PushBack({ 433,779,131,123 }, 0.1f);//4
				die2.PushBack({ 566,779,131,123 }, 0.1f);
				die2.PushBack({ 695,779,131,123 }, 0.1f);
				die2.PushBack({ 1586,846,160,56 }, 0.1f);//1
				die2.PushBack({ 1751,846,160,56 }, 0.1f);
				die2.PushBack({ 1877,909,160,56 }, 0.1f);
				die2.loop = false;
			}

			//dash forward
			{
				dash_forward2.PushBack({ 45, 417, 116, 115 }, 0.3f);
				dash_forward2.PushBack({ 162, 417, 116, 115 }, 0.3f);
				dash_forward2.PushBack({ 277, 417, 116, 115 }, 0.3f);
				dash_forward2.PushBack({ 393, 404, 122, 129 }, 0.3f);
				dash_forward2.PushBack({ 515, 404, 122, 129 }, 0.3f);
				dash_forward2.PushBack({ 638, 404, 122, 129 }, 0.3f);
				dash_forward2.PushBack({ 761, 403, 117, 130 }, 0.3f);
				dash_forward2.PushBack({ 877, 403, 117, 130 }, 0.3f);
				dash_forward2.PushBack({ 393, 404, 122, 129 }, 0.3f);
				dash_forward2.PushBack({ 515, 404, 122, 129 }, 0.3f);
				dash_forward2.PushBack({ 638, 404, 122, 129 }, 0.3f);
				dash_forward2.PushBack({ 45, 417, 116, 115 }, 0.3f);
				dash_forward2.PushBack({ 162, 417, 116, 115 }, 0.3f);
				dash_forward2.PushBack({ 277, 417, 116, 115 }, 0.3f);
				dash_forward2.loop = false;
			}


			//dash backward

			{
				dash_backward2.PushBack({ 368, 579, 106, 156 }, 0.3f);
				dash_backward2.PushBack({ 368, 579, 106, 156 }, 0.3f);
				dash_backward2.PushBack({ 368, 579, 106, 156 }, 0.3f);
				dash_backward2.PushBack({ 46, 579, 107, 156 }, 0.3f);
				dash_backward2.PushBack({ 154, 579, 107, 156 }, 0.3f);
				dash_backward2.PushBack({ 261, 579, 107, 156 }, 0.3f);
				dash_backward2.loop = false;
			}

			// */
		}
	}
}

ModulePlayer::~ModulePlayer() {}

// Load assets
bool ModulePlayer2::Start()
{
	bool ret = true;
	LOG("Loading player 12\n");
	initial_position.x = position.x = shadow_x = 25;
	position.y = initial_position.y = 215;
	lposition = position;
	//player_textures = App->textures->Load("Assets/Sprites/Characters/Haohmaru/Haohmaru.png");
	spritesheet1_2 = App->textures->Load("Assets/Sprites/Characters/Wan-Fu/Wan-Fu2_1.png");
	spritesheet2_2 = App->textures->Load("Assets/Sprites/Characters/Wan-Fu/Wan-Fu2_2.png");
	attack_fx = App->audio->LoadFX("Assets/Audio/Fx/Characters/common/light_attack.wav");
	kick_fx = App->audio->LoadFX("Assets/Audio/Fx/Characters/common/light_kick.wav");
	twister_fx = App->audio->LoadFX("Assets/Audio/Fx/Characters/Haohmaru/twister.wav");
	//hit_fx = App->audio->LoadFX("Assets/Audio/FX/Characters/Haohmaru/Hit_1.wav");
	hit_fx = App->audio->LoadFX("Assets/Audio/FX/Characters/Wan-Fu/Hit_1.wav");
	special_attack_fx = App->audio->LoadFX("Assets/Audio/Fx/Characters/Wan-Fu/special_attack.wav");
	App->ui->player1_point = 0;
	App->ui->player2_point = 0;
	state2 = IDLE2;
	current_animation = &idle2;
	inputs[0] = ' ';
	if (!collider_player_2_up)
		collider_player_2_up = App->collision->AddCollider({ position.x + 15, position.y - 85,30,40 }, COLLIDER_PLAYER, (Module*)App->player);
	if (!collider_player_2_down)
		collider_player_2_down = App->collision->AddCollider({ position.x + 10, position.y - 45,40,45 }, COLLIDER_PLAYER, (Module*)App->player);
	return ret;
}

bool ModulePlayer2::CleanUp() {
	LOG("Unloading player\n");
	App->textures->Unload(player2_textures);
	App->audio->UnLoadFx(attack_fx);
	App->audio->UnLoadFx(kick_fx);
	App->audio->UnLoadFx(hit_fx);
	App->audio->UnLoadFx(twister_fx);
	collider_player_2_up = nullptr;
	collider_player_2_mid = nullptr;
	collider_player_2_down = nullptr;
	collider_player_2_attack = nullptr;
	return true;
}

update_status ModulePlayer2::PreUpdate()
{
	if (!App->is_paused) {
		if (controls) {
			player_input2.pressing_left = App->input->keyboard[SDL_SCANCODE_A] == KEY_REPEAT || SDL_GameControllerGetAxis(App->input->controller_player_1, SDL_CONTROLLER_AXIS_LEFTX) <= -10000;
			player_input2.pressing_right = App->input->keyboard[SDL_SCANCODE_D] == KEY_REPEAT || SDL_GameControllerGetAxis(App->input->controller_player_1, SDL_CONTROLLER_AXIS_LEFTX) >= 10000;
			player_input2.pressing_down = App->input->keyboard[SDL_SCANCODE_S] == KEY_REPEAT || SDL_GameControllerGetAxis(App->input->controller_player_1, SDL_CONTROLLER_AXIS_LEFTY) >= 10000;
			player_input2.pressing_up = App->input->keyboard[SDL_SCANCODE_W] == KEY_DOWN || SDL_GameControllerGetAxis(App->input->controller_player_1, SDL_CONTROLLER_AXIS_LEFTY) <= -10000;
			player_input2.pressing_H = App->input->keyboard[SDL_SCANCODE_H] == KEY_DOWN || App->input->game_pad[SDL_CONTROLLER_BUTTON_X][GAME_PAD_1] == KEY_DOWN;
			player_input2.pressing_J = App->input->keyboard[SDL_SCANCODE_J] == KEY_DOWN || App->input->game_pad[SDL_CONTROLLER_BUTTON_A][GAME_PAD_1] == KEY_DOWN;
			player_input2.pressing_K = App->input->keyboard[SDL_SCANCODE_K] == KEY_DOWN || App->input->game_pad[SDL_CONTROLLER_BUTTON_Y][GAME_PAD_1] == KEY_DOWN;
			player_input2.pressing_L = App->input->keyboard[SDL_SCANCODE_L] == KEY_DOWN || App->input->game_pad[SDL_CONTROLLER_BUTTON_B][GAME_PAD_1] == KEY_DOWN;
			player_input2.pressing_P = App->input->keyboard[SDL_SCANCODE_P] == KEY_DOWN; // || App->input->game_pad[SDL_CONTROLLER_BUTTON_X][GAME_PAD_1] == KEY_DOWN;
			if (player_input2.pressing_left && player_input2.pressing_right) {
				player_input2.pressing_left = false;
				player_input2.pressing_right = false;
			}
		}
		if ((state2 != PUNCH2) && (state2 != KICK2) && (state2 != CROUCH_KICK2) && (state2 != CROUCH_PUNCH2) && (state2 != HEAVY_PUNCH2) && (state2 != HEAVY_KICK2) && (state2 != JUMP_PUNCH2) && (state2 != JUMP_KICK2) && (state2 != JUMP_HEAVY_PUNCH2) && (state2 != JUMP_HEAVY_KICK) && (collider_player_2_attack != nullptr))
		{
			collider_player_2_attack->to_delete = true;
			collider_player_2_attack = nullptr;
		}
		if ((!controls) && (state2 != EN_GARDE2))
		{
			state2 = IDLE2;
		}
		if ((position.y < initial_position.y) && ((state2 != JUMP_BACKWARD2) && (state2 != JUMP_NEUTRAL2) && (state2 != JUMP_FORWARD2) && (state2 != HIT2) && (state2 != SPECIAL_ATTACK_2) && (state2 != JUMP_PUNCH2) && (state2 != JUMP_KICK2) && (state2 != JUMP_HEAVY_PUNCH2) && (state2 != JUMP_HEAVY_KICK2) && (state2 != GRAB2) && (state2 != DASH_BACKWARD2)))
		{
			state2 = JUMP_NEUTRAL2;
		}
		if (life <= 1)
		{
			state2 = DIE2;
		}
		introduceInputs(); //For special attack
		//states 
		{
			if (state2 == IDLE2) {
				if (player_input2.pressing_left)
					state2 = BACKWARD2;
				if (player_input2.pressing_right)
					state2 = FORWARD2;
				if (player_input2.pressing_H) {
					state2 = PUNCH2;
					hit_done++;
					App->audio->PlayFX(attack_fx);
				}
				if (player_input2.pressing_J) {
					state2 = HEAVY_PUNCH2;
					hit_done++;
					App->audio->PlayFX(attack_fx);
				}
				if (player_input2.pressing_K) {
					state2 = KICK2;
					hit_done++;
					App->audio->PlayFX(attack_fx);
				}
				if (player_input2.pressing_L) {
					state2 = HEAVY_KICK2;
					hit_done++;
					App->audio->PlayFX(kick_fx);
				}
				if (player_input2.pressing_P) {
					//This should only be enabled for development

					//App->audio->PlayFX(twister_fx);
					//App->audio->PlayFX(special_attack_fx);
					//hit_done++;
					//state = TWISTER;
					//state = SPECIAL_ATTACK; 
					//App->render->StartCameraShake(1200, 2);
					//App->render->StartSlowdown(750, 20);
				}
				if (player_input2.pressing_up)
					state2 = JUMP_NEUTRAL2;
				if (player_input2.pressing_down)
					state2 = CROUCH_DOWN2;
			}
			if (state2 == BACKWARD2) {
				if (!player_input2.pressing_left)
					state2 = IDLE2;
				if (player_input2.pressing_H) {
					state2 = PUNCH2;
					hit_done++;
					App->audio->PlayFX(attack_fx);
				}
				if (player_input2.pressing_J) {
					state2 = HEAVY_PUNCH2;
					hit_done++;
					App->audio->PlayFX(attack_fx);
				}
				if (player_input2.pressing_K) {
					state2 = KICK2;
					hit_done++;
					App->audio->PlayFX(kick_fx);
				}
				if (player_input2.pressing_L) {
					state2 = HEAVY_KICK2;
					hit_done++;
					App->audio->PlayFX(kick_fx);
				}
				if (player_input2.pressing_up)
					state2 = JUMP_BACKWARD2;
			}
			if (state2 == FORWARD2) {
				if (!player_input2.pressing_right)
					state2 = IDLE2;
				if (player_input2.pressing_H) {
					state2 = PUNCH2;
					hit_done++;
					App->audio->PlayFX(attack_fx);
				}
				if (player_input2.pressing_J) {
					state2 = HEAVY_PUNCH2;
					hit_done++;
					App->audio->PlayFX(attack_fx);
				}
				if (player_input2.pressing_K) {
					state2 = KICK2;
					hit_done++;
					App->audio->PlayFX(attack_fx);
				}
				if (player_input2.pressing_L) {
					state2 = HEAVY_KICK2;
					hit_done++;
					App->audio->PlayFX(kick_fx);
				}
				if (player_input2.pressing_up)
					state2 = JUMP_FORWARD2;
				}
			if (state2 == DASH_BACKWARD2) {
				if (current_animation->Finished()) {
					state2 = IDLE2;
					dash_backward2.Reset();
				}
			}
			if (state2 == DASH_FORWARD) {
				if (current_animation->Finished()) {
					state2 = IDLE2;
					dash_forward2.Reset();
				}
			}
			if (state2 == KICK2) {
				if (current_animation->Finished()) {
					state2 = IDLE2;
					kick2.Reset();
					if (collider_player_2_mid != nullptr)
					{
						collider_player_2_mid->to_delete = true;
						collider_player_2_mid = nullptr;
					}
				}
			}
			if (state2 == PUNCH2) {
				newInput('c'); //If I delete this, special attack doesn't work
				if (current_animation->Finished()) {
					state2 = IDLE2;
					punch2.Reset();
				}
			}
			if (state2 == JUMP_NEUTRAL2)
			{
				direction_x = 0;
				if (player_input2.pressing_H) {
					//hit_done++;
					state2 = JUMP_PUNCH2;
					App->audio->PlayFX(attack_fx);
				}
				if (player_input2.pressing_J)
				{
					state2 = JUMP_HEAVY_PUNCH2;
					App->audio->PlayFX(attack_fx);
				}
				if (player_input2.pressing_K) {
					state2 = JUMP_KICK2;
					App->audio->PlayFX(kick_fx);
					//hit_done++;
				}
				if (player_input2.pressing_L)
				{
					state2 = JUMP_HEAVY_KICK2;
					App->audio->PlayFX(kick_fx);
				}
				if (player_input2.pressing_left && mult == 1)
					state2 = JUMP_BACKWARD2;
				if (player_input2.pressing_right && mult == 1)
					state2 = JUMP_FORWARD2;

				if (current_animation->Finished())
				{
					state2 = IDLE2;
					jump_neutral2.Reset();
				}
			}
			if (state2 == JUMP_FORWARD2)
			{
				direction_x = 1;
				if (player_input2.pressing_H) {
					state2 = JUMP_PUNCH2;
					App->audio->PlayFX(attack_fx);
					hit_done++;
				}
				if (player_input2.pressing_J)
				{
					state2 = JUMP_HEAVY_PUNCH2;
					App->audio->PlayFX(attack_fx);
					hit_done++;
				}
				if (player_input2.pressing_K) {
					state2 = JUMP_KICK2;
					App->audio->PlayFX(kick_fx);
					hit_done++;
				}
				if (player_input2.pressing_L)
				{
					state2 = JUMP_HEAVY_KICK2;
					App->audio->PlayFX(kick_fx);
				}
				if (current_animation->Finished())
				{
					state2 = IDLE2;
					jump_forward2.Reset();
				}
			}
			if (state2 == JUMP_BACKWARD2)
			{
				direction_x = -1;
				if (player_input2.pressing_H) {
					//hit_done++;
					state2 = JUMP_PUNCH2;
					App->audio->PlayFX(attack_fx);
				}
				if (player_input2.pressing_J)
				{
					state2 = JUMP_HEAVY_PUNCH2;
					App->audio->PlayFX(attack_fx);
				}
				if (player_input2.pressing_K) {
					state2 = JUMP_KICK2;
					App->audio->PlayFX(kick_fx);
					//hit_done++;
				}
				if (player_input2.pressing_L)
				{
					state2 = JUMP_HEAVY_KICK2;
					App->audio->PlayFX(kick_fx);
				}
				if (current_animation->Finished())
				{
					state2 = IDLE2;
					jump_backward2.Reset();
				}
			}
			if (state2 == JUMP_PUNCH2) {
				if ((current_animation->Finished()) && (position.y == initial_position.y))
				{
					state2 = IDLE2;
					jump_punch2.Reset();
				}
			}
			if (state2 == JUMP_KICK2) {
				if ((current_animation->Finished()) && (position.y == initial_position.y))
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
				if (player_input2.pressing_H) {
					hit_done++;
					state2 = CROUCH_PUNCH2;
					App->audio->PlayFX(attack_fx);
				}
				if (player_input2.pressing_K) {
					hit_done++;
					state2 = CROUCH_KICK2;
					App->audio->PlayFX(kick_fx);
				}
			}
			if (state2 == CROUCH_UP2)
			{
				if (current_animation->Finished()) {
					state2 = IDLE2;
					crouch_up2.Reset();
				}
			}
			if (state2 == CROUCH_KICK2) {
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
			if (state2 == HEAVY_PUNCH2)
			{
				if (current_animation->Finished())
				{
					heavy_punch2.Reset();
					state2 = IDLE2;
				}
			}
			if (state2 == JUMP_HEAVY_PUNCH)
			{
				if ((current_animation->Finished()) && (position.y == initial_position.y))
				{
					state2 = IDLE2;
					jump_heavy_punch2.Reset();
				}
			}
			if (state2 == HEAVY_KICK)
			{
				if (current_animation->Finished())
				{
					heavy_kick2.Reset();
					state2 = IDLE2;
				}
			}
			if (state2 == JUMP_HEAVY_KICK2)
			{
				if ((current_animation->Finished()) && (position.y == initial_position.y))
				{
					state2 = IDLE2;
					jump_heavy_kick2.Reset();
				}
			}
			if (state2 == HIT2) {
				if (position.y < initial_position.y)
				{
					position.y++;
					if (flip == SDL_FLIP_HORIZONTAL)
					{
						position.x += speed / 4;
					}
					else
					{
						position.x -= speed / 4;
					}
				}
				if (current_animation->Finished()) {
					state2 = IDLE2;
					hit2.Reset();
				}
				if ((position.y == initial_position.y) && (lposition.y < initial_position.y))
				{
					state2 = IDLE2;
					hit2.Reset();
				}
			}
			if (state2 == SPECIAL_ATTACK)
			{
				if (current_animation->Finished())
				{
					specialattack2.Reset();
					are_particles_created2 = false;
					state2 = IDLE2;
				}
			}
			if (state2 == TWISTER2)
			{
				if (current_animation->Finished())
				{
					state2 = IDLE2;
					twister2.Reset();
					are_particles_created2 = false;
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
			if (state2 == WIN2)
			{
				if (current_animation->Finished())
				{
					state2 = IDLE2;
					win2.Reset();
				}
			}
		}
	}
	/*
	if (App->input->keyboard[SDL_SCANCODE_7] == KEY_DOWN) {
		state = States::IDLE;
		current_animation = &idle;
		App->player2->state2 = States2::IDLE2;
		App->player2->current_animation = &App->player2->idle2;
	}
	*/
	return UPDATE_CONTINUE;
}

update_status ModulePlayer2::Update()
{
	lposition = position;
	shadow_x = position.x;

	if (!App->is_paused) {

		switch (state2)
		{
		case IDLE2:
			current_animation = &idle2;
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
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x - 22, position.y - 80);
					collider_player_2_up->SetSize(30, 35);
				}
				if (collider_player_2_down != nullptr)
				{
					collider_player_2_down->SetPos(position.x - 30, position.y - 45);
					collider_player_2_down->SetSize(40, 45);
				}

				shadow_x = position.x;
			}
			else {
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
				shadow_x = position.x + 23;
			}
			break;
		case FORWARD2:
			current_animation = &forward2;
			position.x += speed;
			checkDash(1);
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
			else {
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
			break;
		case BACKWARD2:
			current_animation = &backward2;
			shadow_x = position.x + 10;
			checkDash(2);
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
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x - 15, position.y - 85);
					collider_player_2_up->SetSize(35, 40);
				}
				if (collider_player_2_down != nullptr) {
					collider_player_2_down->SetPos(position.x - 20, position.y - 45);
					collider_player_2_down->SetSize(50, 45);
				}

				shadow_x = position.x;
			}
			else {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x + 25, position.y - 85);
					collider_player_2_up->SetSize(40, 40);
				}
				if (collider_player_2_down != nullptr) {
					collider_player_2_down->SetPos(position.x + 20, position.y - 45);
					collider_player_2_down->SetSize(50, 45);
				}
			}
			position.x -= speed;
			break;

		case CROUCH_DOWN2:
			current_animation = &crouch_down2;

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
					collider_player_2_up->SetSize(35, 35);

					collider_player_2_down->SetPos(position.x - 35, position.y - 30);
					collider_player_2_down->SetSize(50, 30);
				}

				shadow_x -= shadow_w / 3;
			}
			else {
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
			}
			break;
		case CROUCH_UP2:
			current_animation = &crouch_up2;
			break;
		case CROUCH_KICK2:
			current_animation = &crouch_kick2;
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
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x - 30, position.y - 70);
					collider_player_2_up->SetSize(40, 50);
				}
				if (collider_player_2_down != nullptr)
				{
					collider_player_2_down->SetPos(position.x - 30, position.y - 20);
					collider_player_2_down->SetSize(40, 25);
				}
				if (collider_player_2_attack == nullptr) {
					collider_player_2_attack = App->collision->AddCollider({ position.x - 55, position.y - 10,100,20 }, COLLIDER_PLAYER_2_ATTACK, (Module*)App->player2);
					collider_player_2_attack->SetSize(85, 15);
				}
			}
			else {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x + 30, position.y - 70);
					collider_player_2_up->SetSize(40, 50);
				}
				if (collider_player_2_down != nullptr)
				{
					collider_player_2_down->SetPos(position.x + 30, position.y - 20);
					collider_player_2_down->SetSize(40, 25);
				}
				if (collider_player_2_attack == nullptr) {
					collider_player_2_attack = App->collision->AddCollider({ position.x + 25, position.y - 10,100,20 }, COLLIDER_PLAYER_2_ATTACK, (Module*)App->player2);
					collider_player_2_attack->SetSize(85, 15);
				}
				shadow_x = position.x + 30;
			}
			break;
		case CROUCH_PUNCH2:
			current_animation = &crouch_punch2;
			shadow_x = position.x + 20;
			if (flip == SDL_FLIP_HORIZONTAL) {
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
					collider_player_2_attack = App->collision->AddCollider({ position.x - 50, position.y - 50,80,40 }, COLLIDER_PLAYER_2_ATTACK, (Module*)App->player2);
				}

				shadow_x -= shadow_w / 3;
			}
			else {
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
					collider_player_2_attack = App->collision->AddCollider({ position.x + 55, position.y - 50,80,40 }, COLLIDER_PLAYER_2_ATTACK, (Module*)App->player2);
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
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x - 30, position.y - 100);
					collider_player_2_up->SetSize(35, 50);
				}
				if (collider_player_2_down != nullptr)
				{
					collider_player_2_down->SetPos(position.x - 40, position.y - 50);
					collider_player_2_down->SetSize(50, 30);
				}
			}
			else {
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
			}
			break;
		case JUMP_FORWARD2:
			current_animation = &jump_forward2;
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
			else {
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
			position.y -= speed * 1.75 * mult;
			position.x += 1.25*speed;

			if (position.y <= 85) {
				mult = -1;
			}
			else if (position.y > initial_position.y)
			{
				position.y = initial_position.y;
				jump_forward2.Reset();
				mult = 1;
				state2 = IDLE2;
				App->render->StartCameraShake(400, 2);
			}
			break;
		case JUMP_BACKWARD2:
			current_animation = &jump_backward2;

			position.y -= speed * 1.75 * mult;
			position.x -= 1.75*speed;

			if (position.y <= 85) {
				mult = -1;
			}
			else if (position.y == initial_position.y)
			{
				mult = 1;
				jump_backward2.Reset();
				state2 = IDLE2;
				App->render->StartCameraShake(400, 3);
			}
			else if (position.y > initial_position.y)
			{
				position.y = initial_position.y;
				jump_backward2.Reset();
				state2 = IDLE2;
				App->render->StartCameraShake(400, 3);
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
			}
			else {
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
			shadow_x = position.x;
			break;
		case JUMP_PUNCH2:
			current_animation = &jump_punch2;
			//Wan-Fu Jump Punch
			if (flip == SDL_FLIP_HORIZONTAL) {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x - 65, position.y - 80);
					collider_player_2_up->SetSize(80, 35);
				}
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_down->SetPos(position.x - 25, position.y - 45);
					collider_player_2_down->SetSize(60, 47);
				}
				if (collider_player_2_attack == nullptr)
				{
					collider_player_2_attack = App->collision->AddCollider({ position.x, position.y,78,40 }, COLLIDER_PLAYER_2_ATTACK, (Module*)App->player2);
					collider_player_2_attack->to_delete = false;
					collider_player_2_attack->SetPos(position.x + 65, position.y - 70);
					collider_player_2_attack->SetSize(60, 20);
				}
				else
				{
					collider_player_2_attack->SetPos(position.x - 60, position.y - 70);
				}
			}
			else {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x + 35, position.y - 80);
					collider_player_2_up->SetSize(80, 35);
				}
				if (collider_player_2_down != nullptr)
				{
					collider_player_2_down->SetPos(position.x + 25, position.y - 45);
					collider_player_2_down->SetSize(60, 47);
				}
				if (collider_player_2_attack == nullptr)
				{
					collider_player_2_attack = App->collision->AddCollider({ position.x, position.y,78,40 }, COLLIDER_PLAYER_2_ATTACK, (Module*)App->player2);
					collider_player_2_attack->to_delete = false;
					collider_player_2_attack->SetPos(position.x + 65, position.y - 70);
					collider_player_2_attack->SetSize(60, 20);
				}
				else
				{
					collider_player_2_attack->SetPos(position.x + 60, position.y - 70);
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
				jump_punch2.Reset();
				mult = 1;
				state2 = IDLE2;
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
		case JUMP_KICK2:
			current_animation = &jump_kick2;
			//Wan-Fu Jump Kick
			if (flip == SDL_FLIP_HORIZONTAL) {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x - 10, position.y - 75);
					collider_player_2_up->SetSize(40, 55);
				}
				if (collider_player_2_down != nullptr)
				{
					collider_player_2_down->SetPos(position.x - 30, position.y - 50);
					collider_player_2_down->SetSize(60, 35);
				}
				if (collider_player_2_attack == nullptr)
				{
					collider_player_2_attack = App->collision->AddCollider({ position.x, position.y,80,40 }, COLLIDER_PLAYER_1_ATTACK, (Module*)App->player);
					collider_player_2_attack->SetPos(position.x + 55, position.y - 40);
					collider_player_2_attack->SetSize(55, 35);
				}
				else
				{
					collider_player_2_attack->SetPos(position.x - 65, position.y - 30);
				}
			}
			else {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x + 40, position.y - 75);
					collider_player_2_up->SetSize(40, 55);
				}
				if (collider_player_2_down != nullptr)
				{
					collider_player_2_down->SetPos(position.x + 40, position.y - 50);
					collider_player_2_down->SetSize(60, 35);
				}
				if (collider_player_2_attack == nullptr)
				{
					collider_player_2_attack = App->collision->AddCollider({ position.x, position.y,80,40 }, COLLIDER_PLAYER_2_ATTACK, (Module*)App->player2);
					collider_player_2_attack->SetPos(position.x + 55, position.y - 40);
					collider_player_2_attack->SetSize(55, 35);
				}
				else
				{
					collider_player_2_attack->SetPos(position.x + 75, position.y - 30);
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
				jump_kick2.Reset();
				mult = 1;
				state2 = IDLE2;
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
		case PUNCH2:
			current_animation = &punch2;
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
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x - 20, position.y - 60);
					collider_player_2_up->SetSize(50, 47);
				}
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_down->SetPos(position.x - 18, position.y - 10);
					collider_player_2_down->SetSize(70, 15);
				}
				if (collider_player_2_attack == nullptr)
				{
					collider_player_2_attack = App->collision->AddCollider({ position.x, position.y,78,40 }, COLLIDER_PLAYER_2_ATTACK, (Module*)App->player2);
					collider_player_2_attack->to_delete = false;
					collider_player_2_attack->SetPos(position.x - 60, position.y - 50);
					collider_player_2_attack->SetSize(67, 30);
				}
			}
			else {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x + 35, position.y - 60);
					collider_player_2_up->SetSize(50, 47);
				}
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_down->SetPos(position.x + 5, position.y - 10);
					collider_player_2_down->SetSize(70, 15);
				}
				if (collider_player_2_attack == nullptr)
				{
					collider_player_2_attack = App->collision->AddCollider({ position.x, position.y,78,40 }, COLLIDER_PLAYER_2_ATTACK, (Module*)App->player2);
					collider_player_2_attack->to_delete = false;
					collider_player_2_attack->SetPos(position.x + 60, position.y - 50);
					collider_player_2_attack->SetSize(67, 30);
				}
			}
			break;
		case DIE2:
			current_animation = &die2;
			if ((show_fx == true) && (current_animation->SeeCurrentFrame() == 7))
			{
				if (flip == SDL_FLIP_NONE)
				{
					App->particles->AddParticle(App->particles->dust, position.x + 10, position.y - 40);
					App->particles->AddParticle(App->particles->dust, position.x + 50, position.y - 30);
					App->particles->AddParticle(App->particles->dust, position.x + 80, position.y - 40);
					show_fx = false;
				}
				else
				{
					App->particles->AddParticle(App->particles->dust, position.x - 40, position.y - 40);
					App->particles->AddParticle(App->particles->dust, position.x, position.y - 30);
					App->particles->AddParticle(App->particles->dust, position.x + 30, position.y - 40);
					show_fx = false;
				}
			}
			position.y = initial_position.y + 10;
			break;
		case KICK2:
			current_animation = &kick2;
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
					collider_player_2_attack = App->collision->AddCollider({ position.x, position.y,80,40 }, COLLIDER_PLAYER_2_ATTACK, (Module*)App->player2);
					collider_player_2_attack->SetPos(position.x - 50, position.y - 70);
					collider_player_2_attack->SetSize(45, 50);
				}
			}
			else {
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
					collider_player_2_attack = App->collision->AddCollider({ position.x, position.y,80,40 }, COLLIDER_PLAYER_2_ATTACK, (Module*)App->player2);
					collider_player_2_attack->SetPos(position.x + 55, position.y - 70);
					collider_player_2_attack->SetSize(45, 50);
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
			//Wan-Fu Special Attack
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
					App->particles->AddParticle(App->particles->fire_sword, position.x - 50, position.y, COLLIDER_PLAYER_PARTICLES, 0, SDL_FLIP_HORIZONTAL);
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
					App->particles->AddParticle(App->particles->fire_sword, position.x + 50, position.y, COLLIDER_PLAYER_PARTICLES);
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
			break;
		case WIN2:
			current_animation = &win2;
			break;
		case HIT2:
			current_animation = &hit2;
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
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x - 15, position.y - 85);
				}
				if (collider_player_2_down != nullptr)
				{
					collider_player_2_down->SetPos(position.x - 30, position.y - 45);
				}
			}
			else {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x + 15, position.y - 85);
				}
				if (collider_player_2_down != nullptr)
				{
					collider_player_2_down->SetPos(position.x + 10, position.y - 45);
				}
			}
			break;
		case EN_GARDE2:
			current_animation = &en_garde2;
			//Wan-Fu En garde
			if (flip == SDL_FLIP_HORIZONTAL) {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x - 22, position.y - 80);
					collider_player_2_up->SetSize(30, 35);
				}
				if (collider_player_2_down != nullptr)
				{
					collider_player_2_down->SetPos(position.x - 30, position.y - 45);
					collider_player_2_down->SetSize(40, 45);
				}

				shadow_x = position.x;
			}
			else {
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
				shadow_x = position.x + 23;
			}
			break;
		case HEAVY_PUNCH2:
			current_animation = &heavy_punch2;
			//Wan-Fu Heavy Punch
			if (flip == SDL_FLIP_HORIZONTAL) {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x - 15, position.y - 85);
					collider_player_2_up->SetSize(45, 45);
				}
				if (collider_player_2_down != nullptr)
				{
					collider_player_2_down->SetPos(position.x - 25, position.y - 50);
					collider_player_2_down->SetSize(60, 50);
				}
				if (collider_player_2_attack == nullptr)
				{
					collider_player_2_attack = App->collision->AddCollider({ position.x, position.y,78,40 }, COLLIDER_PLAYER_2_ATTACK, (Module*)App->player2);
					collider_player_2_attack->to_delete = false;
					collider_player_2_attack->SetPos(position.x - 45, position.y - 50);
					collider_player_2_attack->SetSize(70, 30);
				}
				if (current_animation->SeeCurrentFrame() > 7)
				{
					if (collider_player_2_up != nullptr)
					{
						collider_player_2_up->SetPos(position.x - 13, position.y - 75);
						collider_player_2_up->SetSize(45, 45);
					}
					if (collider_player_2_down != nullptr)
					{
						collider_player_2_down->SetPos(position.x - 12, position.y - 35);
						collider_player_2_down->SetSize(60, 35);
					}
					if (collider_player_2_attack != nullptr)
					{
						collider_player_2_attack->SetPos(position.x - 80, position.y - 55);
						collider_player_2_attack->SetSize(65, 30);
					}
				}
			}
			else {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x + 20, position.y - 85);
					collider_player_2_up->SetSize(45, 45);
				}
				if (collider_player_2_down != nullptr)
				{
					collider_player_2_down->SetPos(position.x + 15, position.y - 50);
					collider_player_2_down->SetSize(60, 50);
				}
				if (collider_player_2_attack == nullptr)
				{
					collider_player_2_attack = App->collision->AddCollider({ position.x, position.y,78,40 }, COLLIDER_PLAYER_2_ATTACK, (Module*)App->player2);
					collider_player_2_attack->to_delete = false;
					collider_player_2_attack->SetPos(position.x + 35, position.y - 50);
					collider_player_2_attack->SetSize(70, 30);
				}
				if (current_animation->SeeCurrentFrame() > 7)
				{
					if (collider_player_2_up != nullptr)
					{
						collider_player_2_up->SetPos(position.x + 50, position.y - 75);
						collider_player_2_up->SetSize(45, 45);
					}
					if (collider_player_2_down != nullptr)
					{
						collider_player_2_down->SetPos(position.x + 34, position.y - 35);
						collider_player_2_down->SetSize(60, 35);
					}
					if (collider_player_2_attack != nullptr)
					{
						collider_player_2_attack->SetPos(position.x + 96, position.y - 55);
						collider_player_2_attack->SetSize(65, 30);
					}
				}
			}
			shadow_x = position.x;
			break;
		case HEAVY_KICK2:
			current_animation = &heavy_kick2;
			//Wan-Fu Heavy Kick
			if (flip == SDL_FLIP_HORIZONTAL) {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x - 15, position.y - 95);
					collider_player_2_up->SetSize(35, 50);
				}
				if (collider_player_2_down != nullptr)
				{
					collider_player_2_down->SetPos(position.x - 15, position.y - 45);
					collider_player_2_down->SetSize(35, 45);
				}
				if (collider_player_2_attack == nullptr)
				{
					collider_player_2_attack = App->collision->AddCollider({ position.x, position.y,80,40 }, COLLIDER_PLAYER_2_ATTACK, (Module*)App->player2);
					collider_player_2_attack->SetPos(position.x - 60, position.y - 78);
					collider_player_2_attack->SetSize(55, 35);
				}
			}
			else {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x + 35, position.y - 95);
					collider_player_2_up->SetSize(35, 50);
				}
				if (collider_player_2_down != nullptr)
				{
					collider_player_2_down->SetPos(position.x + 35, position.y - 45);
					collider_player_2_down->SetSize(35, 45);
				}
				if (collider_player_2_attack == nullptr)
				{
					collider_player_2_attack = App->collision->AddCollider({ position.x, position.y,80,40 }, COLLIDER_PLAYER_2_ATTACK, (Module*)App->player2);
					collider_player_2_attack->SetPos(position.x + 63, position.y - 78);
					collider_player_2_attack->SetSize(55, 35);
				}
			}
			shadow_x = position.x;
			break;
		case JUMP_HEAVY_PUNCH2:
			current_animation = &jump_heavy_punch2;
			//Wan-Fu Jump Punch
			if (flip == SDL_FLIP_HORIZONTAL) {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x - 65, position.y - 80);
					collider_player_2_up->SetSize(80, 35);
				}
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_down->SetPos(position.x - 25, position.y - 45);
					collider_player_2_down->SetSize(60, 47);
				}
				if (collider_player_2_attack == nullptr)
				{
					collider_player_2_attack = App->collision->AddCollider({ position.x, position.y,78,40 }, COLLIDER_PLAYER_2_ATTACK, (Module*)App->player2);
					collider_player_2_attack->to_delete = false;
					collider_player_2_attack->SetPos(position.x + 65, position.y - 70);
					collider_player_2_attack->SetSize(60, 20);
				}
				else
				{
					collider_player_2_attack->SetPos(position.x - 60, position.y - 70);
				}
			}
			else {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x + 35, position.y - 80);
					collider_player_2_up->SetSize(80, 35);
				}
				if (collider_player_2_down != nullptr)
				{
					collider_player_2_down->SetPos(position.x + 25, position.y - 45);
					collider_player_2_down->SetSize(60, 47);
				}
				if (collider_player_2_attack == nullptr)
				{
					collider_player_2_attack = App->collision->AddCollider({ position.x, position.y,78,40 }, COLLIDER_PLAYER_2_ATTACK, (Module*)App->player2);
					collider_player_2_attack->to_delete = false;
					collider_player_2_attack->SetPos(position.x + 65, position.y - 70);
					collider_player_2_attack->SetSize(60, 20);
				}
				else
				{
					collider_player_2_attack->SetPos(position.x + 60, position.y - 70);
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
				jump_heavy_punch2.Reset();
				mult = 1;
				state2 = IDLE2;
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
		case JUMP_HEAVY_KICK2:
			current_animation = &jump_kick2;
			//Wan-Fu Jump Kick
			if (flip == SDL_FLIP_HORIZONTAL) {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x - 10, position.y - 75);
					collider_player_2_up->SetSize(40, 55);
				}
				if (collider_player_2_down != nullptr)
				{
					collider_player_2_down->SetPos(position.x - 30, position.y - 50);
					collider_player_2_down->SetSize(60, 35);
				}
				if (collider_player_2_attack == nullptr)
				{
					collider_player_2_attack = App->collision->AddCollider({ position.x, position.y,80,40 }, COLLIDER_PLAYER_2_ATTACK, (Module*)App->player2);
					collider_player_2_attack->SetPos(position.x + 55, position.y - 40);
					collider_player_2_attack->SetSize(55, 35);
				}
				else
				{
					collider_player_2_attack->SetPos(position.x - 65, position.y - 30);
				}
			}
			else {
				if (collider_player_2_up != nullptr)
				{
					collider_player_2_up->SetPos(position.x + 40, position.y - 75);
					collider_player_2_up->SetSize(40, 55);
				}
				if (collider_player_2_down != nullptr)
				{
					collider_player_2_down->SetPos(position.x + 40, position.y - 50);
					collider_player_2_down->SetSize(60, 35);
				}
				if (collider_player_2_attack == nullptr)
				{
					collider_player_2_attack = App->collision->AddCollider({ position.x, position.y,80,40 }, COLLIDER_PLAYER_2_ATTACK, (Module*)App->player2);
					collider_player_2_attack->SetPos(position.x + 55, position.y - 40);
					collider_player_2_attack->SetSize(55, 35);
				}
				else
				{
					collider_player_2_attack->SetPos(position.x + 75, position.y - 30);
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
				jump_kick2.Reset();
				mult = 1;
				state2 = IDLE2;
				App->render->StartCameraShake(400, 2);
				direction_x = 0;
			}
			shadow_x = position.x;
			break;
		case DASH_FORWARD2:
			current_animation = &dash_forward2;

			if (flip == SDL_FLIP_HORIZONTAL) {
				position.x -= 2;
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
			else {
				position.x += 4;
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
			break;
		case DASH_BACKWARD2:
			current_animation = &dash_backward2;

			position.y -= speed * 0.1 * mult;
			position.x -= 2 * speed;

			if (position.y <= 80) {
				mult = -0.2;
			}
			else if (position.y == initial_position.y)
			{
				mult = 1;
				dash_backward2.Reset();
				state2 = IDLE2;
				App->render->StartCameraShake(400, 3);
			}
			else if (position.y > initial_position.y)
			{
				position.y = initial_position.y;
				dash_backward2.Reset();
				state2 = IDLE2;
				App->render->StartCameraShake(400, 3);
				mult = 1;
			}
			else if (position.y > initial_position.y)
			{
				position.y = initial_position.y;
				mult = 1;
			}
			if (flip == SDL_FLIP_HORIZONTAL) {
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
			}
			else {
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
			break;
		default:
			LOG("No state found :(");
			break;
		}
	}
	//Draw everything
	SDL_Rect r = current_animation->GetCurrentFrame();
	//haohmaru shadow
	// SDL_Rect shadow = { 1348, 2627, 70, 17 };
	//wan-fu shadow
	SDL_Rect shadow = { 1181,138,91,17 };
	SDL_RendererFlip lflip;
	lflip = flip;
	if ((state2 == DIE2) || (state2 == DASH_BACKWARD2) || (state2 == DASH_FORWARD2))
	{
		player2_textures = spritesheet2_2;
	}
	else
	{
		player2_textures = spritesheet1_2;
	}
	if (position.x < App->player2->position.x + App->player2->current_animation->GetCurrentFrame().w / 2) {
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
	/*if ((state == GRAB) || (state == GRABBED)) {
		flip = gflip;
	}*/
	if (flip == SDL_FLIP_HORIZONTAL) {
		if (shadow_blit) {
			//shadow
			App->render->Blit(spritesheet1_2, shadow_x - shadow.w / 2, initial_position.y - 10, &shadow, flip);
			shadow_blit = false;
		}
		else {
			shadow_blit = true;
		}
		//player
		App->render->Blit(player2_textures, position.x - current_animation->GetCurrentRect().w / 2, position.y - r.h, &r, flip);
	}
	else {
		if (shadow_blit) {
			//shadow
			App->render->Blit(spritesheet1_2, shadow_x, initial_position.y - 10, &shadow, flip);
			shadow_blit = false;
		}
		else {
			shadow_blit = true;
		}
		//player
		App->render->Blit(player2_textures, position.x, position.y - r.h, &r, flip);

	}

	return UPDATE_CONTINUE;
}

void ModulePlayer2::OnCollision(Collider* c1, Collider* c2) {

	if ((state2 != DIE2) && (!App->is_paused)) {
		switch (c2->type)
		{
		case COLLIDER_WALL_LEFT:
			if (!player_input2.pressing_left && state2 != DIE2 && state2 != WIN2)
				position.x += speed;

			break;
		case COLLIDER_WALL_RIGHT:
			if (!player_input2.pressing_left && state2 != DIE2 && state2 != WIN2)
				position.x -= speed;
			break;
		case COLLIDER_PLAYER_2:
			if (((state2 != KICK2) && (state2 != PUNCH2) && (state2 != CROUCH_KICK) && (state2 != CROUCH_PUNCH2)) && (state2 != TWISTER2) && (state2 != DIE2) && (state2 != WIN2) && (state2 != HEAVY_PUNCH2) && (state2 != HEAVY_KICK2))
			{
				if (App->player->position.x > position.x)
				{
					position.x = lposition.x - speed;
				}
				else
				{
					position.x = lposition.x + speed;
				}
			}
			/*	if ((player_input.holding_V)&&(state != GRAB))
				{
					state = GRAB;
					App->player2->state2 = GRABBED2;
					App->player2->gflip = App->player2->flip;
					gposition = App->player2->lposition.x;
				}
				*/
			break;
		case COLLIDER_PLAYER_1_ATTACK:
			if (!App->player->collider_player_attack->to_delete && !god) {
				App->player->hit_percent++;
				App->audio->PlayFX(hit_fx);
				App->judge->state_j = HIT2_J;
				life -= 10;
				state2 = HIT2;
				App->player->collider_player_attack->to_delete = true;
				if ((position.x < App->player->position.x) && (position.x > App->render->left->rect.x + 60))
				{
					position.x -= 10;
				}
				else if ((position.x > App->player2->position.x) && (position.x > App->render->right->rect.x))
				{
					position.x += 10;
				}
				if ((App->player->state == PUNCH) || (App->player->state == HEAVY_PUNCH) || (App->player->state == CROUCH_PUNCH) || (App->player->state == JUMP_HEAVY_PUNCH))
				{
					if (flip == SDL_FLIP_NONE)
					{
						App->particles->AddParticle(App->particles->blood, position.x + 35, position.y - 67.5, COLLIDER_NONE, 0, SDL_FLIP_HORIZONTAL);
					}
					else
					{
						App->particles->AddParticle(App->particles->blood, position.x - 40, position.y - 67.5);
					}
				}
				else if ((App->player->state == KICK) || (App->player->state == HEAVY_KICK) || (App->player->state == CROUCH_KICK) || (App->player->state == JUMP_HEAVY_KICK))
				{
					if (flip == SDL_FLIP_NONE)
					{
						App->particles->AddParticle(App->particles->flash, position.x + 55, position.y - 67.5, COLLIDER_NONE, 0, SDL_FLIP_HORIZONTAL);
					}
					else
					{
						App->particles->AddParticle(App->particles->flash, position.x + 35, position.y - 67.5);
					}
				}

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
				case States::JUMP_PUNCH:
					App->ui->player1_point += 50;
					break;
				case States::JUMP_KICK:
					App->ui->player1_point += 50;
					break;
				default:
					break;
				}
			}
			App->render->StartCameraShake(400, 2);
			App->render->StartSlowdown(800, 30);
			break;
		case COLLIDER_PLAYER_PARTICLES:
			App->audio->PlayFX(hit_fx);
			App->judge->state_j = HIT1_J;
			life -= 20;
			state2 = HIT2;
			if (flip == SDL_FLIP_HORIZONTAL)
			{
				position.x += 5;
			}
			else {
				position.x -= 5;
			}
			App->render->StartCameraShake(400, 2);
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

void ModulePlayer2::PlayerCollidersCleanUp() {
	if (collider_player_2_up != nullptr)
	{
		collider_player_2_up->to_delete = true;
	}
	if (collider_player_2_mid != nullptr)
	{
		collider_player_2_mid->to_delete = true;
	}
	if (collider_player_2_down != nullptr)
	{
		collider_player_2_down->to_delete = true;
	}
}
bool ModulePlayer2::checkSpecialAttack() {

	//Input button combination for special attack	
	int i = 0;
	int j = lastInput;//<- Change this
	int done = 0; //If done = 3. Special attack = true 

	if (flip == SDL_FLIP_HORIZONTAL) {
		while (i < 100) {
			switch (done) {
			case 0:
				if (inputs[j] == 's')//down/crouch
					done++;
				break;
			case 1:
				if (inputs[j] == 'a' || 's')//down and forward
					done++;
				break;
			case 2:
				if (inputs[j] == 'a')//forward
					done++;
				break;
			case 3:
				if (inputs[j] == 'h') //punch				
					return true;
			default:
				//Special attack is false
				return false;
			}

			if (j < 99)
				j++;
			else
				j = 0;

			i++;
		}
	}
	else {
		while (i < 100) {
			switch (done) {
			case 0:
				if (inputs[j] == 's')//down/crouch
					done++;
				break;
			case 1:
				if (inputs[j] == 'd' || 's')//down and forward
					done++;
				break;
			case 2:
				if (inputs[j] == 'd')//forward
					done++;
				break;
			case 3:
				if (inputs[j] == 'h') //punch				
					return true;
			default:
				//Special attack is false
				return false;
			}

			if (j < 99)
				j++;
			else
				j = 0;

			i++;
		}
	}

	
	return false;
}

void ModulePlayer2::newInput(char newInput) {
	if (lastInput > 0)
		lastInput--;
	else
		lastInput = 99;

	//We change first's position 
	if (firstInput == lastInput && firstInput < 99)
		firstInput++;
	else if (firstInput == lastInput && firstInput >= 99)
		firstInput = 0;

	inputs[lastInput] = newInput; //We add the newInput to the last inputs array

}
void ModulePlayer2::introduceInputs() {
	bool isPressingAnything = false;

	if (player_input2.pressing_left) {
		newInput('a');
		isPressingAnything = true;
	}
	if (player_input2.pressing_right) {
		newInput('d');
		isPressingAnything = true;		
	}
	if (player_input2.pressing_down) {
		newInput('s');
		isPressingAnything = true;
		if (checkSpecialAttack())
			state2 = SPECIAL_ATTACK_2;
	}
	if (player_input2.pressing_up) {
		newInput('w');
		isPressingAnything = true;
	}
	if (player_input2.pressing_H) {
		newInput('h');
		isPressingAnything = true;
	}
	if (player_input2.pressing_J) {
		newInput('j');
		isPressingAnything = true;
	}
	if (player_input2.pressing_K) {
		newInput('k');
		isPressingAnything = true;
	}
	if (player_input2.pressing_L) {
		newInput('l');
		isPressingAnything = true;
	}
	if (player_input2.pressing_P) {
		newInput('p');
		isPressingAnything = true;
	}

	if (isPressingAnything == false)
		newInput(' ');
}

void ModulePlayer2::checkDash(int type) {
	//type 1=dash forward. 2=dash backward
	//Input button combination for dash	
	int i = 0;
	int j = lastInput;//<- Change this
	int done = 0; //If done = 2. Dash = true 

	if (flip != SDL_FLIP_HORIZONTAL) {
		//check dash forward
		while (i < 8) {
			switch (done) {
			case 0:
				if (inputs[j] == 'd')//forward
					done++;
				break;
			case 1:
				if (inputs[j] == ' ')//empty
					done++;
				break;
			case 2:
				if (inputs[j] == 'd')//forward
					state2 = DASH_FORWARD2;
				break;
			default:
				//Dash is false
				break;
			}

			if (j < 99)
				j++;
			else
				j = 0;

			i++;
		}
		//check dash backward
		i = 0;
		while (i < 15) {
			switch (done) {
			case 0:
				if (inputs[j] == 'a')//forward
					done++;
				break;
			case 1:
				if (inputs[j] == ' ')//empty
					done++;
				break;
			case 2:
				if (inputs[j] == 'a')//forward
					state2 = DASH_BACKWARD2;
				break;
			default:
				//Dash is false
				break;
			}

			if (j < 99)
				j++;
			else
				j = 0;

			i++;
		}
	}
	else {
		//check dash forward
		while (i < 8) {
			switch (done) {
			case 0:
				if (inputs[j] == 'a')//forward
					done++;
				break;
			case 1:
				if (inputs[j] == ' ')//empty
					done++;
				break;
			case 2:
				if (inputs[j] == 'a')//forward
					state2 = DASH_FORWARD2;
				break;
			default:
				//Dash is false
				break;
			}

			if (j < 99)
				j++;
			else
				j = 0;

			i++;
		}
		//check dash backward
		i = 0;
		while (i < 15) {
			switch (done) {
			case 0:
				if (inputs[j] == 'd')//forward
					done++;
				break;
			case 1:
				if (inputs[j] == ' ')//empty
					done++;
				break;
			case 2:
				if (inputs[j] == 'd')//forward
					state2 = DASH_BACKWARD2;
				break;
			default:
				//Dash is false
				break;
			}

			if (j < 99)
				j++;
			else
				j = 0;

			i++;
		}
	}
}
