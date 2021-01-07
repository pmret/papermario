.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021876C_60921C
/* 60921C 8021876C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 609220 80218770 AFB00010 */  sw        $s0, 0x10($sp)
/* 609224 80218774 0080802D */  daddu     $s0, $a0, $zero
/* 609228 80218778 10A0000E */  beqz      $a1, .L802187B4
/* 60922C 8021877C AFBF0014 */   sw       $ra, 0x14($sp)
/* 609230 80218780 0C04760B */  jal       func_8011D82C
/* 609234 80218784 24040001 */   addiu    $a0, $zero, 1
/* 609238 80218788 0000202D */  daddu     $a0, $zero, $zero
/* 60923C 8021878C 0080282D */  daddu     $a1, $a0, $zero
/* 609240 80218790 0080302D */  daddu     $a2, $a0, $zero
/* 609244 80218794 0080382D */  daddu     $a3, $a0, $zero
/* 609248 80218798 3C028015 */  lui       $v0, %hi(D_801512F0)
/* 60924C 8021879C 8C4212F0 */  lw        $v0, %lo(D_801512F0)($v0)
/* 609250 802187A0 24030001 */  addiu     $v1, $zero, 1
/* 609254 802187A4 0C046F97 */  jal       set_background_color_blend
/* 609258 802187A8 A0430000 */   sb       $v1, ($v0)
/* 60925C 802187AC 24020014 */  addiu     $v0, $zero, 0x14
/* 609260 802187B0 AE020070 */  sw        $v0, 0x70($s0)
.L802187B4:
/* 609264 802187B4 0000202D */  daddu     $a0, $zero, $zero
/* 609268 802187B8 0080282D */  daddu     $a1, $a0, $zero
/* 60926C 802187BC 0080302D */  daddu     $a2, $a0, $zero
/* 609270 802187C0 8E030070 */  lw        $v1, 0x70($s0)
/* 609274 802187C4 24020014 */  addiu     $v0, $zero, 0x14
/* 609278 802187C8 00431023 */  subu      $v0, $v0, $v1
/* 60927C 802187CC 00023880 */  sll       $a3, $v0, 2
/* 609280 802187D0 00E23821 */  addu      $a3, $a3, $v0
/* 609284 802187D4 00073840 */  sll       $a3, $a3, 1
/* 609288 802187D8 0C046F97 */  jal       set_background_color_blend
/* 60928C 802187DC 30E700FE */   andi     $a3, $a3, 0xfe
/* 609290 802187E0 8E020070 */  lw        $v0, 0x70($s0)
/* 609294 802187E4 2442FFFF */  addiu     $v0, $v0, -1
/* 609298 802187E8 AE020070 */  sw        $v0, 0x70($s0)
/* 60929C 802187EC 2C420001 */  sltiu     $v0, $v0, 1
/* 6092A0 802187F0 8FBF0014 */  lw        $ra, 0x14($sp)
/* 6092A4 802187F4 8FB00010 */  lw        $s0, 0x10($sp)
/* 6092A8 802187F8 00021040 */  sll       $v0, $v0, 1
/* 6092AC 802187FC 03E00008 */  jr        $ra
/* 6092B0 80218800 27BD0018 */   addiu    $sp, $sp, 0x18
