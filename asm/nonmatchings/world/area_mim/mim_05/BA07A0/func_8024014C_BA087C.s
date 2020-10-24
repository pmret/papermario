.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024014C_BA087C
/* BA087C 8024014C 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* BA0880 80240150 AFB10034 */  sw        $s1, 0x34($sp)
/* BA0884 80240154 0080882D */  daddu     $s1, $a0, $zero
/* BA0888 80240158 AFBF0038 */  sw        $ra, 0x38($sp)
/* BA088C 8024015C AFB00030 */  sw        $s0, 0x30($sp)
/* BA0890 80240160 8E300148 */  lw        $s0, 0x148($s1)
/* BA0894 80240164 0C00EABB */  jal       get_npc_unsafe
/* BA0898 80240168 86040008 */   lh       $a0, 8($s0)
/* BA089C 8024016C 0040282D */  daddu     $a1, $v0, $zero
/* BA08A0 80240170 94A2008E */  lhu       $v0, 0x8e($a1)
/* BA08A4 80240174 2442FFFF */  addiu     $v0, $v0, -1
/* BA08A8 80240178 A4A2008E */  sh        $v0, 0x8e($a1)
/* BA08AC 8024017C 00021400 */  sll       $v0, $v0, 0x10
/* BA08B0 80240180 1C400023 */  bgtz      $v0, .L80240210
/* BA08B4 80240184 24020004 */   addiu    $v0, $zero, 4
/* BA08B8 80240188 8E0300CC */  lw        $v1, 0xcc($s0)
/* BA08BC 8024018C AE02006C */  sw        $v0, 0x6c($s0)
/* BA08C0 80240190 8C620000 */  lw        $v0, ($v1)
/* BA08C4 80240194 ACA20028 */  sw        $v0, 0x28($a1)
/* BA08C8 80240198 9602007A */  lhu       $v0, 0x7a($s0)
/* BA08CC 8024019C A4A2008E */  sh        $v0, 0x8e($a1)
/* BA08D0 802401A0 8E020078 */  lw        $v0, 0x78($s0)
/* BA08D4 802401A4 28420008 */  slti      $v0, $v0, 8
/* BA08D8 802401A8 14400018 */  bnez      $v0, .L8024020C
/* BA08DC 802401AC 24020021 */   addiu    $v0, $zero, 0x21
/* BA08E0 802401B0 24040003 */  addiu     $a0, $zero, 3
/* BA08E4 802401B4 27A30028 */  addiu     $v1, $sp, 0x28
/* BA08E8 802401B8 84A700A8 */  lh        $a3, 0xa8($a1)
/* BA08EC 802401BC 3C013F80 */  lui       $at, 0x3f80
/* BA08F0 802401C0 44810000 */  mtc1      $at, $f0
/* BA08F4 802401C4 3C014000 */  lui       $at, 0x4000
/* BA08F8 802401C8 44811000 */  mtc1      $at, $f2
/* BA08FC 802401CC 3C01C1A0 */  lui       $at, 0xc1a0
/* BA0900 802401D0 44812000 */  mtc1      $at, $f4
/* BA0904 802401D4 44873000 */  mtc1      $a3, $f6
/* BA0908 802401D8 00000000 */  nop       
/* BA090C 802401DC 468031A0 */  cvt.s.w   $f6, $f6
/* BA0910 802401E0 E7A00010 */  swc1      $f0, 0x10($sp)
/* BA0914 802401E4 E7A20014 */  swc1      $f2, 0x14($sp)
/* BA0918 802401E8 E7A40018 */  swc1      $f4, 0x18($sp)
/* BA091C 802401EC 8E020078 */  lw        $v0, 0x78($s0)
/* BA0920 802401F0 44073000 */  mfc1      $a3, $f6
/* BA0924 802401F4 0000302D */  daddu     $a2, $zero, $zero
/* BA0928 802401F8 AFA30020 */  sw        $v1, 0x20($sp)
/* BA092C 802401FC 2442FFFF */  addiu     $v0, $v0, -1
/* BA0930 80240200 0C01BFA4 */  jal       fx_emote
/* BA0934 80240204 AFA2001C */   sw       $v0, 0x1c($sp)
/* BA0938 80240208 24020021 */  addiu     $v0, $zero, 0x21
.L8024020C:
/* BA093C 8024020C AE220070 */  sw        $v0, 0x70($s1)
.L80240210:
/* BA0940 80240210 8FBF0038 */  lw        $ra, 0x38($sp)
/* BA0944 80240214 8FB10034 */  lw        $s1, 0x34($sp)
/* BA0948 80240218 8FB00030 */  lw        $s0, 0x30($sp)
/* BA094C 8024021C 03E00008 */  jr        $ra
/* BA0950 80240220 27BD0040 */   addiu    $sp, $sp, 0x40
