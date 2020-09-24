.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel inflict_partner_ko
/* 194B34 80266254 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 194B38 80266258 2402000D */  addiu     $v0, $zero, 0xd
/* 194B3C 8026625C 14A20013 */  bne       $a1, $v0, .L802662AC
/* 194B40 80266260 AFBF0010 */   sw       $ra, 0x10($sp)
/* 194B44 80266264 80820216 */  lb        $v0, 0x216($a0)
/* 194B48 80266268 10450007 */  beq       $v0, $a1, .L80266288
/* 194B4C 8026626C 00000000 */   nop      
/* 194B50 80266270 0C0997D0 */  jal       inflict_status
/* 194B54 80266274 2405000D */   addiu    $a1, $zero, 0xd
/* 194B58 80266278 0C05272D */  jal       play_sound
/* 194B5C 8026627C 24042107 */   addiu    $a0, $zero, 0x2107
/* 194B60 80266280 080998AB */  j         .L802662AC
/* 194B64 80266284 00000000 */   nop      
.L80266288:
/* 194B68 80266288 90820217 */  lbu       $v0, 0x217($a0)
/* 194B6C 8026628C 00461021 */  addu      $v0, $v0, $a2
/* 194B70 80266290 A0820217 */  sb        $v0, 0x217($a0)
/* 194B74 80266294 00021600 */  sll       $v0, $v0, 0x18
/* 194B78 80266298 00021603 */  sra       $v0, $v0, 0x18
/* 194B7C 8026629C 2842000A */  slti      $v0, $v0, 0xa
/* 194B80 802662A0 14400002 */  bnez      $v0, .L802662AC
/* 194B84 802662A4 24020009 */   addiu    $v0, $zero, 9
/* 194B88 802662A8 A0820217 */  sb        $v0, 0x217($a0)
.L802662AC:
/* 194B8C 802662AC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 194B90 802662B0 24020001 */  addiu     $v0, $zero, 1
/* 194B94 802662B4 03E00008 */  jr        $ra
/* 194B98 802662B8 27BD0018 */   addiu    $sp, $sp, 0x18
