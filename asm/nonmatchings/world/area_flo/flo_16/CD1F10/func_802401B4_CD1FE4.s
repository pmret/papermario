.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802401B4_CD1FE4
/* CD1FE4 802401B4 3C028011 */  lui       $v0, %hi(gPlayerData)
/* CD1FE8 802401B8 2442F290 */  addiu     $v0, $v0, %lo(gPlayerData)
/* CD1FEC 802401BC 000420C0 */  sll       $a0, $a0, 3
/* CD1FF0 802401C0 00822021 */  addu      $a0, $a0, $v0
/* CD1FF4 802401C4 90820014 */  lbu       $v0, 0x14($a0)
/* CD1FF8 802401C8 10400009 */  beqz      $v0, .L802401F0
/* CD1FFC 802401CC 00000000 */   nop      
/* CD2000 802401D0 90820015 */  lbu       $v0, 0x15($a0)
/* CD2004 802401D4 00022600 */  sll       $a0, $v0, 0x18
/* CD2008 802401D8 00041E03 */  sra       $v1, $a0, 0x18
/* CD200C 802401DC 00051400 */  sll       $v0, $a1, 0x10
/* CD2010 802401E0 00021403 */  sra       $v0, $v0, 0x10
/* CD2014 802401E4 0043102A */  slt       $v0, $v0, $v1
/* CD2018 802401E8 10400003 */  beqz      $v0, .L802401F8
/* CD201C 802401EC 00000000 */   nop      
.L802401F0:
/* CD2020 802401F0 03E00008 */  jr        $ra
/* CD2024 802401F4 2402FFFF */   addiu    $v0, $zero, -1
.L802401F8:
/* CD2028 802401F8 03E00008 */  jr        $ra
/* CD202C 802401FC 00041603 */   sra      $v0, $a0, 0x18
