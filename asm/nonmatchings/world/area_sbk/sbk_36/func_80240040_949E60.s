.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240040_949EA0
/* 949EA0 80240040 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 949EA4 80240044 F7B40018 */  sdc1      $f20, 0x18($sp)
/* 949EA8 80240048 4485A000 */  mtc1      $a1, $f20
/* 949EAC 8024004C F7B60020 */  sdc1      $f22, 0x20($sp)
/* 949EB0 80240050 4486B000 */  mtc1      $a2, $f22
/* 949EB4 80240054 AFB00010 */  sw        $s0, 0x10($sp)
/* 949EB8 80240058 F7B80028 */  sdc1      $f24, 0x28($sp)
/* 949EBC 8024005C 4487C000 */  mtc1      $a3, $f24
/* 949EC0 80240060 AFBF0014 */  sw        $ra, 0x14($sp)
/* 949EC4 80240064 0C019D28 */  jal       guMtxIdentF
/* 949EC8 80240068 0080802D */   daddu    $s0, $a0, $zero
/* 949ECC 8024006C 4616A582 */  mul.s     $f22, $f20, $f22
/* 949ED0 80240070 00000000 */  nop       
/* 949ED4 80240074 4618A502 */  mul.s     $f20, $f20, $f24
/* 949ED8 80240078 00000000 */  nop       
/* 949EDC 8024007C 3C013F80 */  lui       $at, 0x3f80
/* 949EE0 80240080 44810000 */  mtc1      $at, $f0
/* 949EE4 80240084 00000000 */  nop       
/* 949EE8 80240088 E6000014 */  swc1      $f0, 0x14($s0)
/* 949EEC 8024008C E6160010 */  swc1      $f22, 0x10($s0)
/* 949EF0 80240090 E6140018 */  swc1      $f20, 0x18($s0)
/* 949EF4 80240094 8FBF0014 */  lw        $ra, 0x14($sp)
/* 949EF8 80240098 8FB00010 */  lw        $s0, 0x10($sp)
/* 949EFC 8024009C D7B80028 */  ldc1      $f24, 0x28($sp)
/* 949F00 802400A0 D7B60020 */  ldc1      $f22, 0x20($sp)
/* 949F04 802400A4 D7B40018 */  ldc1      $f20, 0x18($sp)
/* 949F08 802400A8 03E00008 */  jr        $ra
/* 949F0C 802400AC 27BD0030 */   addiu    $sp, $sp, 0x30
