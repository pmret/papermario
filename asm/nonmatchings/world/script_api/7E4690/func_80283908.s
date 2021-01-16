.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80283908
/* 7E4788 80283908 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 7E478C 8028390C 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 7E4790 80283910 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 7E4794 80283914 AFB00010 */  sw        $s0, 0x10($sp)
/* 7E4798 80283918 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* 7E479C 8028391C 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* 7E47A0 80283920 AFBF001C */  sw        $ra, 0x1c($sp)
/* 7E47A4 80283924 AFB20018 */  sw        $s2, 0x18($sp)
/* 7E47A8 80283928 AFB10014 */  sw        $s1, 0x14($sp)
/* 7E47AC 8028392C 84620160 */  lh        $v0, 0x160($v1)
/* 7E47B0 80283930 0200882D */  daddu     $s1, $s0, $zero
/* 7E47B4 80283934 44820000 */  mtc1      $v0, $f0
/* 7E47B8 80283938 00000000 */  nop
/* 7E47BC 8028393C 46800020 */  cvt.s.w   $f0, $f0
/* 7E47C0 80283940 E6000028 */  swc1      $f0, 0x28($s0)
/* 7E47C4 80283944 84620162 */  lh        $v0, 0x162($v1)
/* 7E47C8 80283948 3C04800B */  lui       $a0, %hi(gCameras)
/* 7E47CC 8028394C 24841D80 */  addiu     $a0, $a0, %lo(gCameras)
/* 7E47D0 80283950 44820000 */  mtc1      $v0, $f0
/* 7E47D4 80283954 00000000 */  nop
/* 7E47D8 80283958 46800020 */  cvt.s.w   $f0, $f0
/* 7E47DC 8028395C E600002C */  swc1      $f0, 0x2c($s0)
/* 7E47E0 80283960 84620164 */  lh        $v0, 0x164($v1)
/* 7E47E4 80283964 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 7E47E8 80283968 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 7E47EC 8028396C 44820000 */  mtc1      $v0, $f0
/* 7E47F0 80283970 00000000 */  nop
/* 7E47F4 80283974 46800020 */  cvt.s.w   $f0, $f0
/* 7E47F8 80283978 00031080 */  sll       $v0, $v1, 2
/* 7E47FC 8028397C 00431021 */  addu      $v0, $v0, $v1
/* 7E4800 80283980 00021080 */  sll       $v0, $v0, 2
/* 7E4804 80283984 00431023 */  subu      $v0, $v0, $v1
/* 7E4808 80283988 000218C0 */  sll       $v1, $v0, 3
/* 7E480C 8028398C 00431021 */  addu      $v0, $v0, $v1
/* 7E4810 80283990 000210C0 */  sll       $v0, $v0, 3
/* 7E4814 80283994 E6000030 */  swc1      $f0, 0x30($s0)
/* 7E4818 80283998 3C038011 */  lui       $v1, %hi(gPlayerData+0x12)
/* 7E481C 8028399C 8063F2A2 */  lb        $v1, %lo(gPlayerData+0x12)($v1)
/* 7E4820 802839A0 10600022 */  beqz      $v1, .L80283A2C
/* 7E4824 802839A4 00449021 */   addu     $s2, $v0, $a0
/* 7E4828 802839A8 0C00EABB */  jal       get_npc_unsafe
/* 7E482C 802839AC 2404FFFC */   addiu    $a0, $zero, -4
/* 7E4830 802839B0 C60200A8 */  lwc1      $f2, 0xa8($s0)
/* 7E4834 802839B4 3C014334 */  lui       $at, 0x4334
/* 7E4838 802839B8 44810000 */  mtc1      $at, $f0
/* 7E483C 802839BC 3C01C2B4 */  lui       $at, 0xc2b4
/* 7E4840 802839C0 44816000 */  mtc1      $at, $f12
/* 7E4844 802839C4 4600103C */  c.lt.s    $f2, $f0
/* 7E4848 802839C8 00000000 */  nop
/* 7E484C 802839CC 45000003 */  bc1f      .L802839DC
/* 7E4850 802839D0 0040802D */   daddu    $s0, $v0, $zero
/* 7E4854 802839D4 3C0142B4 */  lui       $at, 0x42b4
/* 7E4858 802839D8 44816000 */  mtc1      $at, $f12
.L802839DC:
/* 7E485C 802839DC 0C00A6C9 */  jal       clamp_angle
/* 7E4860 802839E0 00000000 */   nop
/* 7E4864 802839E4 C6220028 */  lwc1      $f2, 0x28($s1)
/* 7E4868 802839E8 E6020038 */  swc1      $f2, 0x38($s0)
/* 7E486C 802839EC C622002C */  lwc1      $f2, 0x2c($s1)
/* 7E4870 802839F0 E602003C */  swc1      $f2, 0x3c($s0)
/* 7E4874 802839F4 C6220030 */  lwc1      $f2, 0x30($s1)
/* 7E4878 802839F8 26040038 */  addiu     $a0, $s0, 0x38
/* 7E487C 802839FC E6020040 */  swc1      $f2, 0x40($s0)
/* 7E4880 80283A00 862200B2 */  lh        $v0, 0xb2($s1)
/* 7E4884 80283A04 44070000 */  mfc1      $a3, $f0
/* 7E4888 80283A08 24420005 */  addiu     $v0, $v0, 5
/* 7E488C 80283A0C 44822000 */  mtc1      $v0, $f4
/* 7E4890 80283A10 00000000 */  nop
/* 7E4894 80283A14 46802120 */  cvt.s.w   $f4, $f4
/* 7E4898 80283A18 44062000 */  mfc1      $a2, $f4
/* 7E489C 80283A1C 0C00A7E7 */  jal       add_vec2D_polar
/* 7E48A0 80283A20 26050040 */   addiu    $a1, $s0, 0x40
/* 7E48A4 80283A24 0C03BCCA */  jal       enable_partner_ai
/* 7E48A8 80283A28 00000000 */   nop
.L80283A2C:
/* 7E48AC 80283A2C 24020001 */  addiu     $v0, $zero, 1
/* 7E48B0 80283A30 A6420008 */  sh        $v0, 8($s2)
/* 7E48B4 80283A34 8FBF001C */  lw        $ra, 0x1c($sp)
/* 7E48B8 80283A38 8FB20018 */  lw        $s2, 0x18($sp)
/* 7E48BC 80283A3C 8FB10014 */  lw        $s1, 0x14($sp)
/* 7E48C0 80283A40 8FB00010 */  lw        $s0, 0x10($sp)
/* 7E48C4 80283A44 24020002 */  addiu     $v0, $zero, 2
/* 7E48C8 80283A48 03E00008 */  jr        $ra
/* 7E48CC 80283A4C 27BD0020 */   addiu    $sp, $sp, 0x20
