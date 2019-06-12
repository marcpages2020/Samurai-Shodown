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
				win.PushBack({ 620, 1711, 110, 118 }, 0.1f);
				win.PushBack({ 759, 1711, 110, 118 }, 0.1f);
				win.PushBack({ 896, 1711, 110, 116 }, 0.1f);
				win.PushBack({ 1032, 1711, 110, 116 }, 0.1f);
				win.PushBack({ 1170, 1711, 110, 116 }, 0.1f);
				win.PushBack({ 1303, 1711, 110, 120 }, 0.1f);
				win.PushBack({ 1433, 1711, 110, 120 }, 0.1f);
				win.PushBack({ 1558, 1711, 110, 120 }, 0.1f);
				win.loop = true;
			}

			//jump punch

			{
				jump_punch.PushBack({ 820, 635, 115, 112 }, 0.3f);//1
				jump_punch.PushBack({ 956, 635, 115, 112 }, 0.3f);
				jump_punch.PushBack({ 1087, 635, 115, 112 }, 0.3f);
				jump_punch.PushBack({ 1227, 619, 108, 136 }, 0.3f);
				jump_punch.PushBack({ 1355, 619, 108, 136 }, 0.3f);
				jump_punch.PushBack({ 1487, 619, 108, 136 }, 0.3f);
				jump_punch.PushBack({ 1611, 621, 125, 130 }, 0.3f);
				jump_punch.PushBack({ 1766, 619, 125, 130 }, 0.3f);
				jump_punch.PushBack({ 1914, 619, 125, 130 }, 0.3f);
				jump_punch.PushBack({ 1443, 764, 119, 130 }, 0.3f);
				jump_punch.PushBack({ 1586, 764, 119, 130 }, 0.3f);
				jump_punch.PushBack({ 1750, 764, 119, 130 }, 0.3f);
				jump_punch.loop = false;
			}
			//jump kick
			{
				jump_kick.PushBack({ 30, 1831, 111, 104 }, 0.3f);
				jump_kick.PushBack({ 164, 1831, 111, 104 }, 0.3f);
				jump_kick.PushBack({ 313, 1831, 111, 104 }, 0.3f);
				jump_kick.PushBack({ 466, 1831, 132, 110 }, 0.3f);
				jump_kick.PushBack({ 625, 1831, 132, 110 }, 0.3f);
				jump_kick.PushBack({ 1271, 1831, 132, 110 }, 0.3f);
				jump_kick.PushBack({ 790, 1827, 133, 124 }, 0.3f);
				jump_kick.PushBack({ 949, 1827, 133, 124 }, 0.3f);
				jump_kick.PushBack({ 1112, 1827, 133, 124 }, 0.3f);
				jump_kick.loop = false;
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

			//jump heavy punch
			{
				jump_heavy_punch.PushBack({ 820, 635, 115, 112 }, 0.3f);//1
				jump_heavy_punch.PushBack({ 956, 635, 115, 112 }, 0.3f);
				jump_heavy_punch.PushBack({ 1089, 635, 115, 112 }, 0.3f);
				jump_heavy_punch.PushBack({ 1227, 619, 108, 136 }, 0.3f);
				jump_heavy_punch.PushBack({ 1255, 619, 108, 136 }, 0.3f);
				jump_heavy_punch.PushBack({ 1487, 619, 108, 136 }, 0.3f);
				jump_heavy_punch.PushBack({ 1619, 621, 125, 130 }, 0.3f);
				jump_heavy_punch.PushBack({ 1766, 619, 125, 130 }, 0.3f);
				jump_heavy_punch.PushBack({ 1914, 619, 125, 130 }, 0.3f);
				jump_heavy_punch.PushBack({ 1443, 764, 119, 130 }, 0.3f);
				jump_heavy_punch.PushBack({ 1586, 764, 119, 130 }, 0.3f);
				jump_heavy_punch.PushBack({ 1750, 764, 119, 130 }, 0.3f);
				jump_heavy_punch.loop = false;
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
				die.PushBack({ 45,746,127,156 }, 0.1f);//1
				die.PushBack({ 172,746,127,156 }, 0.1f);
				die.PushBack({ 300,746,127,156 }, 0.1f);
				die.PushBack({ 433,779,131,123 }, 0.1f);//4
				die.PushBack({ 566,779,131,123 }, 0.1f);
				die.PushBack({ 695,779,131,123 }, 0.1f);
				die.PushBack({ 824,826,120,76 }, 0.1f);//1
				die.PushBack({ 945,826,120,76 }, 0.1f);
				die.PushBack({ 1068,826,120,76 }, 0.1f);
				die.PushBack({ 433,779,131,123 }, 0.1f);//4
				die.PushBack({ 566,779,131,123 }, 0.1f);
				die.PushBack({ 695,779,131,123 }, 0.1f);
				die.PushBack({ 1586,846,160,56 }, 0.1f);//1
				die.PushBack({ 1751,846,160,56 }, 0.1f);
				die.PushBack({ 1877,909,160,56 }, 0.1f);
				die.loop = false;
			}

			//dash forward
			{
				dash_forward.PushBack({ 45, 417, 116, 115}, 0.3f);
				dash_forward.PushBack({ 162, 417, 116, 115 }, 0.3f);
				dash_forward.PushBack({ 277, 417, 116, 115 }, 0.3f);
				dash_forward.PushBack({ 393, 404, 122, 129}, 0.3f);
				dash_forward.PushBack({ 515, 404, 122, 129}, 0.3f);
				dash_forward.PushBack({ 638, 404, 122, 129}, 0.3f);
				dash_forward.PushBack({ 761, 403, 117, 130}, 0.3f);
				dash_forward.PushBack({ 877, 403, 117, 130}, 0.3f);
				dash_forward.PushBack({ 393, 404, 122, 129}, 0.3f);
				dash_forward.PushBack({ 515, 404, 122, 129}, 0.3f);
				dash_forward.PushBack({ 638, 404, 122, 129}, 0.3f);
				dash_forward.PushBack({ 45, 417, 116, 115 }, 0.3f);
				dash_forward.PushBack({ 162, 417, 116, 115 }, 0.3f);
				dash_forward.PushBack({ 277, 417, 116, 115 }, 0.3f);
				dash_forward.loop = false;
			}

			//dash backward			
			{
				dash_backward.PushBack({ 368, 579, 106, 156}, 2.5f);
				dash_backward.PushBack({ 368, 579, 106, 156 }, 2.5f);
				dash_backward.PushBack({ 368, 579, 106, 156 }, 2.5f);
				dash_backward.PushBack({ 46, 579, 107, 156 }, 2.5f);
				dash_backward.PushBack({ 154, 579, 107, 156 }, 2.5f);
				dash_backward.PushBack({ 261, 579, 107, 156 }, 2.5f);
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
	spritesheet1 = App->textures->Load("Assets/Sprites/Characters/Wan-Fu/Wan-Fu1_1.png");
	spritesheet2 = App->textures->Load("Assets/Sprites/Characters/Wan-Fu/Wan-Fu1_2.png");
	attack_fx = App->audio->LoadFX("Assets/Audio/Fx/Characters/common/light_attack.wav");
	kick_fx = App->audio->LoadFX("Assets/Audio/Fx/Characters/common/light_kick.wav");
	hit_fx = App->audio->LoadFX("Assets/Audio/FX/Characters/Wan-Fu/Hit_1.wav");
	special_attack_fx = App->audio->LoadFX("Assets/Audio/Fx/Characters/Wan-Fu/special_attack.wav");
	App->ui->player1_point = 0;
	App->ui->player2_point = 0;
	state = IDLE;
	current_animation = &idle;
	inputs[0] = ' ';	
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
		if (player_input.pressing_Q)
		{
			state = SPECIAL_ATTACK;
		}
		if (player_input.pressing_E)
		{
			App->player2->state2 = SPECIAL_ATTACK_2;
		}
		if ((state != PUNCH) && (state != KICK) && (state != CROUCH_KICK) && (state != CROUCH_PUNCH) && (state != HEAVY_PUNCH) && (state != HEAVY_KICK) && (state != JUMP_PUNCH) && (state != JUMP_KICK) && (state != JUMP_HEAVY_PUNCH) && (state != JUMP_HEAVY_KICK) && (collider_player_attack != nullptr))
		{
			collider_player_attack->to_delete = true;
			collider_player_attack = nullptr;
		}
		if ((player_input.pressing_F4)) {
			god = !god;
		}
		if ((!controls) && (state != EN_GARDE))
		{
			state = IDLE;
		}
		if ((position.y < initial_position.y) && ((state != JUMP_BACKWARD) && (state != JUMP_NEUTRAL) && (state != JUMP_FORWARD) && (state != HIT) && (state != SPECIAL_ATTACK) && (state != JUMP_PUNCH) && (state != JUMP_KICK) && (state != JUMP_HEAVY_PUNCH) && (state != JUMP_HEAVY_KICK) && (state != DASH_BACKWARD)))
		{
			state = JUMP_NEUTRAL;
		}
		if (life <= 1)
		{
			state = DIE;
		}
		introduceInputs(); //For special attack
		//states 
		{
			if (state == IDLE) {		
				if (player_input.pressing_A)
					state = BACKWARD;
				if (player_input.pressing_D)
					state = FORWARD;				
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
					//This should only be enabled for development

					//App->audio->PlayFX(twister_fx);
					//App->audio->PlayFX(special_attack_fx);
					//hit_done++;
					//state = TWISTER;
					//state = SPECIAL_ATTACK; 
					//App->render->StartCameraShake(1200, 2);
					//App->render->StartSlowdown(750, 20);
				}
				if (player_input.pressing_W)
					state = JUMP_NEUTRAL;
				if (player_input.pressing_S)
					state = CROUCH_DOWN;
			}
			if (state == BACKWARD) {				
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
				if (player_input.pressing_W)
					state = JUMP_BACKWARD;
			}
			if (state == FORWARD) {
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
				if (player_input.pressing_W)
					state = JUMP_FORWARD;
			}
			if (state == DASH_BACKWARD) {
				if (position.y > initial_position.y) {
					state = IDLE;
					position.y = initial_position.y;
					dash_backward.Reset();
				}
			}
			if (state == DASH_FORWARD) {
				if (current_animation->Finished()) {
					state = IDLE;
					dash_forward.Reset();
				}
			}
			if (state == KICK) {
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
				newInput('c'); //If I delete this, special attack doesn't work
				if (current_animation->Finished()) {
					state = IDLE;
					punch.Reset();
				}
			}
			if (state == JUMP_NEUTRAL)
			{
				direction_x = 0;
				if (player_input.pressing_C) {
					state = JUMP_PUNCH;
					App->audio->PlayFX(attack_fx);
				}
				if (player_input.pressing_V)
				{
					state = JUMP_HEAVY_PUNCH;
					App->audio->PlayFX(attack_fx);
				}
				if (player_input.pressing_B) {
					state = JUMP_KICK;
					App->audio->PlayFX(kick_fx);
				}
				if (player_input.pressing_N)
				{
					state = JUMP_HEAVY_KICK;
					App->audio->PlayFX(kick_fx);
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
				direction_x = 1;
				if (player_input.pressing_C) {
					state = JUMP_PUNCH;
					App->audio->PlayFX(attack_fx);
					hit_done++;
				}
				if (player_input.pressing_V)
				{
					state = JUMP_HEAVY_PUNCH;
					App->audio->PlayFX(attack_fx);
					hit_done++;
				}
				if (player_input.pressing_B) {
					state = JUMP_KICK;
					App->audio->PlayFX(kick_fx);
					hit_done++;
				}
				if (player_input.pressing_N)
				{
					state = JUMP_HEAVY_KICK;
					App->audio->PlayFX(kick_fx);
				}
				if (current_animation->Finished())
				{
					state = IDLE;
					jump_forward.Reset();
				}
			}
			if (state == JUMP_BACKWARD)
			{
				direction_x = -1;
				if (player_input.pressing_C) {
					state = JUMP_PUNCH;
					App->audio->PlayFX(attack_fx);
				}
				if (player_input.pressing_V)
				{
					state = JUMP_HEAVY_PUNCH;
					App->audio->PlayFX(attack_fx);
				}
				if (player_input.pressing_B) {
					state = JUMP_KICK;
					App->audio->PlayFX(kick_fx);
				}
				if (player_input.pressing_N)
				{
					state = JUMP_HEAVY_KICK;
					App->audio->PlayFX(kick_fx);
				}
				if (current_animation->Finished())
				{
					state = IDLE;
					jump_backward.Reset();
				}
			}
			if (state == JUMP_PUNCH) {
				if ((current_animation->Finished())&&(position.y == initial_position.y))
				{
					state = IDLE;
					jump_punch.Reset();
				}
			}
			if (state == JUMP_KICK) {
				if ((current_animation->Finished())&&(position.y == initial_position.y))
				{
					state = IDLE;
					jump_kick.Reset();
				}
			}
			if (state == CROUCH_DOWN)
			{
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
			if (state == CROUCH_KICK) {
				if (current_animation->Finished()) {
					state = IDLE;
					crouch_kick.Reset();
				}
			}
			if (state == CROUCH_PUNCH) {
				if (current_animation->Finished()) {
					state = IDLE;
					crouch_punch.Reset();
				}
			}
			if (state == HEAVY_PUNCH)
			{
				if (current_animation->Finished())
				{
					heavy_punch.Reset();
					state = IDLE;
				}
			}
			if (state == JUMP_HEAVY_PUNCH)
			{
				if ((current_animation->Finished()) && (position.y == initial_position.y))
				{
					state = IDLE;
					jump_heavy_punch.Reset();
				}
			}
			if (state == HEAVY_KICK)
			{
				if (current_animation->Finished())
				{
					heavy_kick.Reset();
					state = IDLE;
				}
			}
			if (state == JUMP_HEAVY_KICK)
			{
				if ((current_animation->Finished()) && (position.y == initial_position.y))
				{
					state = IDLE;
					jump_heavy_kick.Reset();
				}
			}
			if (state == HIT) {
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
					state = IDLE;
					hit.Reset();
				}
				if ((position.y == initial_position.y)&&(lposition.y < initial_position.y))
				{
					state = IDLE;
					hit.Reset();
				}
			}
			if (state == SPECIAL_ATTACK)
			{
				if (current_animation->Finished())
				{
					specialattack.Reset();
					are_particles_created = false;
					state = IDLE;
				}
			}
			if (state == EN_GARDE)
			{
				if (current_animation->Finished())
				{
					state = IDLE;
					en_garde.Reset();
				}
			}
			if (state == WIN)
			{
				if (current_animation->Finished())
				{
					state = IDLE;
					win.Reset();
				}
			}
		}
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
			checkDash(1);
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
			checkDash(2);

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

			if (flip == SDL_FLIP_HORIZONTAL) {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x - 30, position.y - 70);
					collider_player_up->SetSize(40, 50);
				}
				if (collider_player_down != nullptr)
				{
					collider_player_down->SetPos(position.x - 30, position.y - 20);
					collider_player_down->SetSize(40, 25);
				}
				if (collider_player_attack == nullptr) {
					collider_player_attack = App->collision->AddCollider({ position.x - 55, position.y - 10,100,20 }, COLLIDER_PLAYER_1_ATTACK, (Module*)App->player);
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
			}
			else if (position.y > initial_position.y)
			{
				position.y = initial_position.y;
				mult = 1;
			}
			
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
			}
			else if (position.y > initial_position.y)
			{
				position.y = initial_position.y;
				jump_backward.Reset();
				state = IDLE;
				mult = 1;
			}
			
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

			if (flip == SDL_FLIP_HORIZONTAL) {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x - 65, position.y - 80);
					collider_player_up->SetSize(80, 35);
				}
				if (collider_player_up != nullptr)
				{
					collider_player_down->SetPos(position.x - 25, position.y - 45);
					collider_player_down->SetSize(60, 47);
				}
				if (collider_player_attack == nullptr)
				{
					collider_player_attack = App->collision->AddCollider({ position.x, position.y,78,40 }, COLLIDER_PLAYER_1_ATTACK, (Module*)App->player);
					collider_player_attack->to_delete = false;
					collider_player_attack->SetPos(position.x + 65, position.y - 70);
					collider_player_attack->SetSize(60, 20);
				}
				else
				{
					collider_player_attack->SetPos(position.x - 60, position.y - 70);
				}
			}
			else {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x + 35, position.y - 80);
					collider_player_up->SetSize(80, 35);
				}
				if (collider_player_down != nullptr)
				{
					collider_player_down->SetPos(position.x + 25, position.y - 45);
					collider_player_down->SetSize(60, 47);
				}
				if (collider_player_attack == nullptr)
				{
					collider_player_attack = App->collision->AddCollider({ position.x, position.y,78,40 }, COLLIDER_PLAYER_1_ATTACK, (Module*)App->player);
					collider_player_attack->to_delete = false;
					collider_player_attack->SetPos(position.x + 65, position.y - 70);
					collider_player_attack->SetSize(60, 20);
				}
				else
				{
					collider_player_attack->SetPos(position.x + 60, position.y - 70);
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
			
			if (flip == SDL_FLIP_HORIZONTAL) {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x - 10, position.y - 75);
					collider_player_up->SetSize(40, 55);
				}
				if (collider_player_down != nullptr)
				{
					collider_player_down->SetPos(position.x - 30, position.y - 50);
					collider_player_down->SetSize(60, 35);
				}
				if (collider_player_attack == nullptr)
				{
					collider_player_attack = App->collision->AddCollider({ position.x, position.y,80,40 }, COLLIDER_PLAYER_1_ATTACK, (Module*)App->player);
					collider_player_attack->SetPos(position.x + 55, position.y - 40);
					collider_player_attack->SetSize(55, 35);
				}
				else
				{
					collider_player_attack->SetPos(position.x - 65, position.y - 30);
				}
			}
			else {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x + 40, position.y - 75);
					collider_player_up->SetSize(40, 55);
				}
				if (collider_player_down != nullptr)
				{
					collider_player_down->SetPos(position.x + 40, position.y - 50);
					collider_player_down->SetSize(60, 35);
				}
				if (collider_player_attack == nullptr)
				{
					collider_player_attack = App->collision->AddCollider({ position.x, position.y,80,40 }, COLLIDER_PLAYER_1_ATTACK, (Module*)App->player);
					collider_player_attack->SetPos(position.x + 55, position.y - 40);
					collider_player_attack->SetSize(55, 35);
				}
				else
				{
					collider_player_attack->SetPos(position.x + 75, position.y - 30);
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
					collider_player_attack = App->collision->AddCollider({ position.x, position.y,78,40 }, COLLIDER_PLAYER_1_ATTACK, (Module*)App->player);
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
					collider_player_attack = App->collision->AddCollider({ position.x, position.y,78,40 }, COLLIDER_PLAYER_1_ATTACK, (Module*)App->player);
					collider_player_attack->to_delete = false;
					collider_player_attack->SetPos(position.x + 60, position.y - 50);
					collider_player_attack->SetSize(67, 30);
				}
			}
			break;
		case DIE:
			current_animation = &die;
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
		case KICK:
			current_animation = &kick;
			
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
			break;
		case SPECIAL_ATTACK:
			current_animation = &specialattack;
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
					App->particles->AddParticle(App->particles->fire_sword, position.x - 60, position.y-90, COLLIDER_PLAYER_PARTICLES,0,SDL_FLIP_HORIZONTAL);
					are_particles_created = true;
				}
				position.x += 1.5 * speed;
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
					App->particles->AddParticle(App->particles->fire_sword, position.x + 50, position.y-90, COLLIDER_PLAYER_PARTICLES);
					are_particles_created = true;
				}
				position.x -= 1.5 * speed;
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
			break;
		case WIN:
			current_animation = &win;
			break;
		case HIT:
			current_animation = &hit;
			shadow_x = position.x;

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
					collider_player_attack = App->collision->AddCollider({ position.x, position.y,78,40 }, COLLIDER_PLAYER_1_ATTACK, (Module*)App->player);
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
					collider_player_attack = App->collision->AddCollider({ position.x, position.y,78,40 }, COLLIDER_PLAYER_1_ATTACK, (Module*)App->player);
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
					collider_player_attack = App->collision->AddCollider({ position.x, position.y,80,40 }, COLLIDER_PLAYER_1_ATTACK, (Module*)App->player);
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
					collider_player_attack = App->collision->AddCollider({ position.x, position.y,80,40 }, COLLIDER_PLAYER_1_ATTACK, (Module*)App->player);
					collider_player_attack->SetPos(position.x + 63, position.y - 78);
					collider_player_attack->SetSize(55, 35);
				}
			}
			shadow_x = position.x;
			break;
		case JUMP_HEAVY_PUNCH:
			current_animation = &jump_heavy_punch;
			
			if (flip == SDL_FLIP_HORIZONTAL) {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x - 65, position.y - 80);
					collider_player_up->SetSize(80, 35);
				}
				if (collider_player_up != nullptr)
				{
					collider_player_down->SetPos(position.x - 25, position.y - 45);
					collider_player_down->SetSize(60, 47);
				}
				if (collider_player_attack == nullptr)
				{
					collider_player_attack = App->collision->AddCollider({ position.x, position.y,78,40 }, COLLIDER_PLAYER_1_ATTACK, (Module*)App->player);
					collider_player_attack->to_delete = false;
					collider_player_attack->SetPos(position.x + 65, position.y - 70);
					collider_player_attack->SetSize(60, 20);
				}
				else
				{
					collider_player_attack->SetPos(position.x - 60, position.y - 70);
				}
			}
			else {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x + 35, position.y - 80);
					collider_player_up->SetSize(80, 35);
				}
				if (collider_player_down != nullptr)
				{
					collider_player_down->SetPos(position.x + 25, position.y - 45);
					collider_player_down->SetSize(60, 47);
				}
				if (collider_player_attack == nullptr)
				{
					collider_player_attack = App->collision->AddCollider({ position.x, position.y,78,40 }, COLLIDER_PLAYER_1_ATTACK, (Module*)App->player);
					collider_player_attack->to_delete = false;
					collider_player_attack->SetPos(position.x + 65, position.y - 70);
					collider_player_attack->SetSize(60, 20);
				}
				else
				{
					collider_player_attack->SetPos(position.x + 60, position.y - 70);
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
				jump_heavy_punch.Reset();
				mult = 1;
				state = IDLE;
				direction_x = 0;
			}
			else if (position.y > initial_position.y)
			{
				position.y = initial_position.y;
				mult = 1;
			}
			shadow_x = position.x;
			break;
		case JUMP_HEAVY_KICK:
			current_animation = &jump_kick;
			
			if (flip == SDL_FLIP_HORIZONTAL) {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x - 10, position.y - 75);
					collider_player_up->SetSize(40, 55);
				}
				if (collider_player_down != nullptr)
				{
					collider_player_down->SetPos(position.x - 30, position.y - 50);
					collider_player_down->SetSize(60, 35);
				}
				if (collider_player_attack == nullptr)
				{
					collider_player_attack = App->collision->AddCollider({ position.x, position.y,80,40 }, COLLIDER_PLAYER_1_ATTACK, (Module*)App->player);
					collider_player_attack->SetPos(position.x + 55, position.y - 40);
					collider_player_attack->SetSize(55, 35);
				}
				else
				{
					collider_player_attack->SetPos(position.x - 65, position.y - 30);
				}
			}
			else {
				if (collider_player_up != nullptr)
				{
					collider_player_up->SetPos(position.x + 40, position.y - 75);
					collider_player_up->SetSize(40, 55);
				}
				if (collider_player_down != nullptr)
				{
					collider_player_down->SetPos(position.x + 40, position.y - 50);
					collider_player_down->SetSize(60, 35);
				}
				if (collider_player_attack == nullptr)
				{
					collider_player_attack = App->collision->AddCollider({ position.x, position.y,80,40 }, COLLIDER_PLAYER_1_ATTACK, (Module*)App->player);
					collider_player_attack->SetPos(position.x + 55, position.y - 40);
					collider_player_attack->SetSize(55, 35);
				}
				else
				{
					collider_player_attack->SetPos(position.x + 75, position.y - 30);
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
				direction_x = 0;
			}
			shadow_x = position.x;
			break;
		case DASH_FORWARD:
			current_animation = &dash_forward;
			
			if (flip == SDL_FLIP_HORIZONTAL) {
				position.x -= 2;
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
				position.x += 3;
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
		case DASH_BACKWARD:
			current_animation = &dash_backward;
			if (flip == SDL_FLIP_HORIZONTAL)
			{
				position.x += 1.75*speed;
			}
			else
			{
				position.x -= 1.75*speed;
			}
			position.y -= speed * 1.25 * mult;

			if (position.y <= 180) {
				mult = -1;
			}
			else if (position.y == initial_position.y)
			{
				mult = 1;
				dash_backward.Reset();
				state = IDLE;
			}
			else if (position.y > initial_position.y)
			{
				position.y = initial_position.y;
				dash_backward.Reset();
				state = IDLE;
				mult = 1;
			}
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
			break;
		default:
			LOG("No state found :(");
			break;
		}
	}
	//Draw everything
	SDL_Rect r = current_animation->GetCurrentFrame();
	SDL_Rect shadow = { 1181,138,91,17 };
	SDL_RendererFlip lflip;
	lflip = flip;
	if ((state == DASH_BACKWARD)||(state == DASH_FORWARD))
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
			App->render->Blit(spritesheet1, shadow_x - shadow.w / 2, initial_position.y - 10, &shadow, flip);
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
			App->render->Blit(spritesheet1, shadow_x, initial_position.y - 10, &shadow, flip);
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
	if (App->scene_wanfu)
	{

	}
	if ((state != DIE) && (!App->is_paused)) {
		switch (c2->type)
		{
		case COLLIDER_WALL_LEFT:
			if (!player_input.pressing_D && state != DIE && state != WIN)
				position.x += 1.5*speed;
				break;
		case COLLIDER_WALL_RIGHT:
			if (!player_input.pressing_A && state != DIE && state != WIN)
				position.x -= 1.5*speed;
			break;
		case COLLIDER_PLAYER_2:
			if (((state != KICK) && (state != PUNCH) && (state != CROUCH_KICK) && (state != CROUCH_PUNCH)) && (state != DIE) && (state != WIN) && (state != HEAVY_PUNCH) && (state != HEAVY_KICK))
			{
					if (App->player2->position.x > position.x)
					{
						position.x = lposition.x - speed;
					}
					else
					{
						position.x = lposition.x + speed;
					}
			}
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
				if ((App->player2->state2 == PUNCH2)||(App->player2->state2 == HEAVY_PUNCH2)||(App->player2->state2 == CROUCH_PUNCH2)||(App->player2->state2 == JUMP_HEAVY_PUNCH2))
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
				else if ((App->player2->state2 == KICK2) || (App->player2->state2 == HEAVY_KICK2)|| (App->player2->state2 == CROUCH_KICK2)||(App->player2->state2 == JUMP_HEAVY_KICK2))
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
	int j = lastInput;//<- Change this
	int done = 0; //If done = 3. Special attack = true 
	
	if (flip != SDL_FLIP_HORIZONTAL) {
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
				if (inputs[j] == 'c') //punch				
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
				if (inputs[j] == 'a' || 's')//down and forward
					done++;
				break;
			case 2:
				if (inputs[j] == 'a')//forward
					done++;
				break;
			case 3:
				if (inputs[j] == 'c') //punch				
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

void ModulePlayer::newInput(char newInput) {
	if (lastInput >0)
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

void ModulePlayer::introduceInputs() {
	bool isPressingAnything = false;

	if (player_input.pressing_S) {
		newInput('s');
		isPressingAnything = true;
		if (checkSpecialAttack())
			state = SPECIAL_ATTACK;
	}
	if (player_input.pressing_D) {
		newInput('d');
		isPressingAnything = true;
	}
	if (player_input.pressing_C) {
		newInput('c');
		isPressingAnything = true;
	}
	if (player_input.pressing_A) {
		newInput('a');
		isPressingAnything = true;
	}
	if (player_input.pressing_S) {
		newInput('s');
		isPressingAnything = true;
	}
	if (player_input.pressing_W) {
		newInput('w');
		isPressingAnything = true;
	}
	if (player_input.pressing_V) {
		newInput('v');
		isPressingAnything = true;
	}
	if (player_input.pressing_E) {
		newInput('e');
		isPressingAnything = true;
	}
	if (player_input.pressing_B) {
		newInput('b');
		isPressingAnything = true;
	}
	if (player_input.pressing_N) {
		newInput('n');
		isPressingAnything = true;
	}
	if (player_input.pressing_M) {
		newInput('m');
		isPressingAnything = true;
	}
	if (player_input.pressing_Q) {
		newInput('q');
		isPressingAnything = true;
	}

	if (isPressingAnything == false)
		newInput(' ');
}

void ModulePlayer::checkDash(int type) {
	//type 1=dash forward. 2=dash backward
	//Input button combination for dash	
	int i = 0;
	int j = lastInput;
	int done = 0; //If done = 2. Dash = true 

	if (flip != SDL_FLIP_HORIZONTAL) {
		//check dash forward
		if (type == 1) {
			while (i < 8) {
				switch (done) {
				case 0:
					if (inputs[j] == 'd')//forward
						done++;
					else if (inputs[j] != ' ')
						done = 3;
					break;
				case 1:
					if (inputs[j] == ' ')//empty
						done++;
					else if (inputs[j] != 'd' || inputs[j] != ' ')
						done = 3;
					break;
				case 2:
					if (inputs[j] == 'd')//forward
						state = DASH_FORWARD;
					//else if (inputs[j] != 'd' || inputs[j] != ' ')
					//	done = 3;
					break;
				case 3:
					//Dash is false
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
		if (type == 2) {
			//check dash backward
			i = 0;
			j = lastInput;
			done = 0; //If done = 2. Dash = true 
			while (i < 8) {
				switch (done) {
				case 0:
					if (inputs[j] == 'a')//forward
						done++;
					break;
				case 1:
					if (inputs[j] == ' ')//empty
						done++;
					else if (inputs[j] != 'a')
						done = 3;
					break;
				case 2:
					if (inputs[j] == 'a')//forward
						state = DASH_BACKWARD;
					else if (inputs[j] != ' ')
						done = 3;
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
	else {
		if (type == 2) {
			//check dash forward
			i = 0;
			j = lastInput;
			done = 0; //If done = 2. Dash = true 
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
						state = DASH_FORWARD;
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
		if (type == 1) {
			//check dash backward
			i = 0;
			j = lastInput;
			done = 0; //If done = 2. Dash = true 
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
						state = DASH_BACKWARD;
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
}
