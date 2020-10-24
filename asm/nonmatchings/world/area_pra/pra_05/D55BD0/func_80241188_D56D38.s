.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241188_D56D38
/* D56D38 80241188 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D56D3C 8024118C AFB00010 */  sw        $s0, 0x10($sp)
/* D56D40 80241190 0080802D */  daddu     $s0, $a0, $zero
/* D56D44 80241194 AFBF0014 */  sw        $ra, 0x14($sp)
/* D56D48 80241198 8E02000C */  lw        $v0, 0xc($s0)
/* D56D4C 8024119C 0C0B1EAF */  jal       get_variable
/* D56D50 802411A0 8C450000 */   lw       $a1, ($v0)
/* D56D54 802411A4 00021140 */  sll       $v0, $v0, 5
/* D56D58 802411A8 AE000084 */  sw        $zero, 0x84($s0)
/* D56D5C 802411AC 3C018008 */  lui       $at, 0x8008
/* D56D60 802411B0 00220821 */  addu      $at, $at, $v0
/* D56D64 802411B4 942278F8 */  lhu       $v0, 0x78f8($at)
/* D56D68 802411B8 30420040 */  andi      $v0, $v0, 0x40
/* D56D6C 802411BC 10400002 */  beqz      $v0, .L802411C8
/* D56D70 802411C0 24020001 */   addiu    $v0, $zero, 1
/* D56D74 802411C4 AE020084 */  sw        $v0, 0x84($s0)
.L802411C8:
/* D56D78 802411C8 8FBF0014 */  lw        $ra, 0x14($sp)
/* D56D7C 802411CC 8FB00010 */  lw        $s0, 0x10($sp)
/* D56D80 802411D0 24020002 */  addiu     $v0, $zero, 2
/* D56D84 802411D4 03E00008 */  jr        $ra
/* D56D88 802411D8 27BD0018 */   addiu    $sp, $sp, 0x18
/* D56D8C 802411DC 00000000 */  nop       
