.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240040_CF0980
/* CF0980 80240040 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* CF0984 80240044 F7B40018 */  sdc1      $f20, 0x18($sp)
/* CF0988 80240048 4485A000 */  mtc1      $a1, $f20
/* CF098C 8024004C F7B60020 */  sdc1      $f22, 0x20($sp)
/* CF0990 80240050 4486B000 */  mtc1      $a2, $f22
/* CF0994 80240054 AFB00010 */  sw        $s0, 0x10($sp)
/* CF0998 80240058 F7B80028 */  sdc1      $f24, 0x28($sp)
/* CF099C 8024005C 4487C000 */  mtc1      $a3, $f24
/* CF09A0 80240060 AFBF0014 */  sw        $ra, 0x14($sp)
/* CF09A4 80240064 0C019D28 */  jal       guMtxIdentF
/* CF09A8 80240068 0080802D */   daddu    $s0, $a0, $zero
/* CF09AC 8024006C 4616A582 */  mul.s     $f22, $f20, $f22
/* CF09B0 80240070 00000000 */  nop       
/* CF09B4 80240074 4618A502 */  mul.s     $f20, $f20, $f24
/* CF09B8 80240078 00000000 */  nop       
/* CF09BC 8024007C 3C013F80 */  lui       $at, 0x3f80
/* CF09C0 80240080 44810000 */  mtc1      $at, $f0
/* CF09C4 80240084 00000000 */  nop       
/* CF09C8 80240088 E6000014 */  swc1      $f0, 0x14($s0)
/* CF09CC 8024008C E6160010 */  swc1      $f22, 0x10($s0)
/* CF09D0 80240090 E6140018 */  swc1      $f20, 0x18($s0)
/* CF09D4 80240094 8FBF0014 */  lw        $ra, 0x14($sp)
/* CF09D8 80240098 8FB00010 */  lw        $s0, 0x10($sp)
/* CF09DC 8024009C D7B80028 */  ldc1      $f24, 0x28($sp)
/* CF09E0 802400A0 D7B60020 */  ldc1      $f22, 0x20($sp)
/* CF09E4 802400A4 D7B40018 */  ldc1      $f20, 0x18($sp)
/* CF09E8 802400A8 03E00008 */  jr        $ra
/* CF09EC 802400AC 27BD0030 */   addiu    $sp, $sp, 0x30
