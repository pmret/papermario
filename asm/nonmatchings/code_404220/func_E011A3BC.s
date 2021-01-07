.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E011A3BC
/* 4045DC E011A3BC 0080482D */  daddu     $t1, $a0, $zero
/* 4045E0 E011A3C0 00091400 */  sll       $v0, $t1, 0x10
/* 4045E4 E011A3C4 00021403 */  sra       $v0, $v0, 0x10
/* 4045E8 E011A3C8 240300FF */  addiu     $v1, $zero, 0xff
/* 4045EC E011A3CC 14430015 */  bne       $v0, $v1, .LE011A424
/* 4045F0 E011A3D0 3C07E200 */   lui      $a3, 0xe200
/* 4045F4 E011A3D4 34E7001C */  ori       $a3, $a3, 0x1c
/* 4045F8 E011A3D8 3C050055 */  lui       $a1, 0x55
/* 4045FC E011A3DC 34A51208 */  ori       $a1, $a1, 0x1208
/* 404600 E011A3E0 3C08FCFF */  lui       $t0, 0xfcff
/* 404604 E011A3E4 3508FFFF */  ori       $t0, $t0, 0xffff
/* 404608 E011A3E8 3C06FFFC */  lui       $a2, 0xfffc
/* 40460C E011A3EC 3C04800A */  lui       $a0, %hi(D_8009A66C)
/* 404610 E011A3F0 2484A66C */  addiu     $a0, $a0, %lo(D_8009A66C)
/* 404614 E011A3F4 8C820000 */  lw        $v0, ($a0)
/* 404618 E011A3F8 34C6F279 */  ori       $a2, $a2, 0xf279
/* 40461C E011A3FC 0040182D */  daddu     $v1, $v0, $zero
/* 404620 E011A400 24420008 */  addiu     $v0, $v0, 8
/* 404624 E011A404 AC820000 */  sw        $v0, ($a0)
/* 404628 E011A408 AC670000 */  sw        $a3, ($v1)
/* 40462C E011A40C AC650004 */  sw        $a1, 4($v1)
/* 404630 E011A410 24430008 */  addiu     $v1, $v0, 8
/* 404634 E011A414 AC830000 */  sw        $v1, ($a0)
/* 404638 E011A418 AC480000 */  sw        $t0, ($v0)
/* 40463C E011A41C 03E00008 */  jr        $ra
/* 404640 E011A420 AC460004 */   sw       $a2, 4($v0)
.LE011A424:
/* 404644 E011A424 34E7001C */  ori       $a3, $a3, 0x1c
/* 404648 E011A428 3C050050 */  lui       $a1, 0x50
/* 40464C E011A42C 34A54340 */  ori       $a1, $a1, 0x4340
/* 404650 E011A430 3C08FCFF */  lui       $t0, 0xfcff
/* 404654 E011A434 3508B3FF */  ori       $t0, $t0, 0xb3ff
/* 404658 E011A438 3C06FF64 */  lui       $a2, 0xff64
/* 40465C E011A43C 3C04800A */  lui       $a0, %hi(D_8009A66C)
/* 404660 E011A440 2484A66C */  addiu     $a0, $a0, %lo(D_8009A66C)
/* 404664 E011A444 8C820000 */  lw        $v0, ($a0)
/* 404668 E011A448 34C6FE7F */  ori       $a2, $a2, 0xfe7f
/* 40466C E011A44C 0040182D */  daddu     $v1, $v0, $zero
/* 404670 E011A450 24420008 */  addiu     $v0, $v0, 8
/* 404674 E011A454 AC820000 */  sw        $v0, ($a0)
/* 404678 E011A458 AC670000 */  sw        $a3, ($v1)
/* 40467C E011A45C AC650004 */  sw        $a1, 4($v1)
/* 404680 E011A460 24430008 */  addiu     $v1, $v0, 8
/* 404684 E011A464 AC830000 */  sw        $v1, ($a0)
/* 404688 E011A468 24430010 */  addiu     $v1, $v0, 0x10
/* 40468C E011A46C AC480000 */  sw        $t0, ($v0)
/* 404690 E011A470 AC460004 */  sw        $a2, 4($v0)
/* 404694 E011A474 AC830000 */  sw        $v1, ($a0)
/* 404698 E011A478 3C03FA00 */  lui       $v1, 0xfa00
/* 40469C E011A47C AC430008 */  sw        $v1, 8($v0)
/* 4046A0 E011A480 312300FF */  andi      $v1, $t1, 0xff
/* 4046A4 E011A484 03E00008 */  jr        $ra
/* 4046A8 E011A488 AC43000C */   sw       $v1, 0xc($v0)
