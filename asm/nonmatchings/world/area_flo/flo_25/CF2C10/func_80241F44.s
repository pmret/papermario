.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241F44
/* CF4B14 80241F44 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CF4B18 80241F48 AFB00010 */  sw        $s0, 0x10($sp)
/* CF4B1C 80241F4C 0080802D */  daddu     $s0, $a0, $zero
/* CF4B20 80241F50 AFBF0014 */  sw        $ra, 0x14($sp)
/* CF4B24 80241F54 8E02000C */  lw        $v0, 0xc($s0)
/* CF4B28 80241F58 0C0B1EAF */  jal       get_variable
/* CF4B2C 80241F5C 8C450000 */   lw       $a1, ($v0)
/* CF4B30 80241F60 3C048008 */  lui       $a0, %hi(gItemTable)
/* CF4B34 80241F64 248478E0 */  addiu     $a0, $a0, %lo(gItemTable)
/* CF4B38 80241F68 00021940 */  sll       $v1, $v0, 5
/* CF4B3C 80241F6C 00642021 */  addu      $a0, $v1, $a0
/* CF4B40 80241F70 240300BB */  addiu     $v1, $zero, 0xbb
/* CF4B44 80241F74 14430003 */  bne       $v0, $v1, .L80241F84
/* CF4B48 80241F78 24020002 */   addiu    $v0, $zero, 2
/* CF4B4C 80241F7C 080907E8 */  j         .L80241FA0
/* CF4B50 80241F80 AE0200A8 */   sw       $v0, 0xa8($s0)
.L80241F84:
/* CF4B54 80241F84 94820018 */  lhu       $v0, 0x18($a0)
/* CF4B58 80241F88 30420080 */  andi      $v0, $v0, 0x80
/* CF4B5C 80241F8C 10400003 */  beqz      $v0, .L80241F9C
/* CF4B60 80241F90 24020001 */   addiu    $v0, $zero, 1
/* CF4B64 80241F94 080907E8 */  j         .L80241FA0
/* CF4B68 80241F98 AE0200A8 */   sw       $v0, 0xa8($s0)
.L80241F9C:
/* CF4B6C 80241F9C AE0000A8 */  sw        $zero, 0xa8($s0)
.L80241FA0:
/* CF4B70 80241FA0 8FBF0014 */  lw        $ra, 0x14($sp)
/* CF4B74 80241FA4 8FB00010 */  lw        $s0, 0x10($sp)
/* CF4B78 80241FA8 24020002 */  addiu     $v0, $zero, 2
/* CF4B7C 80241FAC 03E00008 */  jr        $ra
/* CF4B80 80241FB0 27BD0018 */   addiu    $sp, $sp, 0x18
