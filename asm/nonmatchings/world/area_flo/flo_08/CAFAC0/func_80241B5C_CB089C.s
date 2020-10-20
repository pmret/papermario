.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241B5C_CB089C
/* CB089C 80241B5C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CB08A0 80241B60 AFB00010 */  sw        $s0, 0x10($sp)
/* CB08A4 80241B64 0080802D */  daddu     $s0, $a0, $zero
/* CB08A8 80241B68 AFBF0014 */  sw        $ra, 0x14($sp)
/* CB08AC 80241B6C 8E02000C */  lw        $v0, 0xc($s0)
/* CB08B0 80241B70 0C0B1EAF */  jal       get_variable
/* CB08B4 80241B74 8C450000 */   lw       $a1, ($v0)
/* CB08B8 80241B78 3C048008 */  lui       $a0, %hi(gItemTable)
/* CB08BC 80241B7C 248478E0 */  addiu     $a0, $a0, %lo(gItemTable)
/* CB08C0 80241B80 00021940 */  sll       $v1, $v0, 5
/* CB08C4 80241B84 00642021 */  addu      $a0, $v1, $a0
/* CB08C8 80241B88 240300BB */  addiu     $v1, $zero, 0xbb
/* CB08CC 80241B8C 14430003 */  bne       $v0, $v1, .L80241B9C
/* CB08D0 80241B90 24020002 */   addiu    $v0, $zero, 2
/* CB08D4 80241B94 080906EE */  j         .L80241BB8
/* CB08D8 80241B98 AE0200A8 */   sw       $v0, 0xa8($s0)
.L80241B9C:
/* CB08DC 80241B9C 94820018 */  lhu       $v0, 0x18($a0)
/* CB08E0 80241BA0 30420080 */  andi      $v0, $v0, 0x80
/* CB08E4 80241BA4 10400003 */  beqz      $v0, .L80241BB4
/* CB08E8 80241BA8 24020001 */   addiu    $v0, $zero, 1
/* CB08EC 80241BAC 080906EE */  j         .L80241BB8
/* CB08F0 80241BB0 AE0200A8 */   sw       $v0, 0xa8($s0)
.L80241BB4:
/* CB08F4 80241BB4 AE0000A8 */  sw        $zero, 0xa8($s0)
.L80241BB8:
/* CB08F8 80241BB8 8FBF0014 */  lw        $ra, 0x14($sp)
/* CB08FC 80241BBC 8FB00010 */  lw        $s0, 0x10($sp)
/* CB0900 80241BC0 24020002 */  addiu     $v0, $zero, 2
/* CB0904 80241BC4 03E00008 */  jr        $ra
/* CB0908 80241BC8 27BD0018 */   addiu    $sp, $sp, 0x18
