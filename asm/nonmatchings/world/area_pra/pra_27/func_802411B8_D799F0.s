.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802411B8_D7ABA8
/* D7ABA8 802411B8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D7ABAC 802411BC AFB00010 */  sw        $s0, 0x10($sp)
/* D7ABB0 802411C0 0080802D */  daddu     $s0, $a0, $zero
/* D7ABB4 802411C4 AFBF0014 */  sw        $ra, 0x14($sp)
/* D7ABB8 802411C8 8E02000C */  lw        $v0, 0xc($s0)
/* D7ABBC 802411CC 0C0B1EAF */  jal       get_variable
/* D7ABC0 802411D0 8C450000 */   lw       $a1, ($v0)
/* D7ABC4 802411D4 00021140 */  sll       $v0, $v0, 5
/* D7ABC8 802411D8 AE000084 */  sw        $zero, 0x84($s0)
/* D7ABCC 802411DC 3C018008 */  lui       $at, 0x8008
/* D7ABD0 802411E0 00220821 */  addu      $at, $at, $v0
/* D7ABD4 802411E4 942278F8 */  lhu       $v0, 0x78f8($at)
/* D7ABD8 802411E8 30420040 */  andi      $v0, $v0, 0x40
/* D7ABDC 802411EC 10400002 */  beqz      $v0, .L802411F8
/* D7ABE0 802411F0 24020001 */   addiu    $v0, $zero, 1
/* D7ABE4 802411F4 AE020084 */  sw        $v0, 0x84($s0)
.L802411F8:
/* D7ABE8 802411F8 8FBF0014 */  lw        $ra, 0x14($sp)
/* D7ABEC 802411FC 8FB00010 */  lw        $s0, 0x10($sp)
/* D7ABF0 80241200 24020002 */  addiu     $v0, $zero, 2
/* D7ABF4 80241204 03E00008 */  jr        $ra
/* D7ABF8 80241208 27BD0018 */   addiu    $sp, $sp, 0x18
/* D7ABFC 8024120C 00000000 */  nop       
