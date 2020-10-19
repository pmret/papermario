.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240384_AFDEC4
/* AFDEC4 80240384 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* AFDEC8 80240388 AFB10014 */  sw        $s1, 0x14($sp)
/* AFDECC 8024038C 0080882D */  daddu     $s1, $a0, $zero
/* AFDED0 80240390 AFBF0018 */  sw        $ra, 0x18($sp)
/* AFDED4 80240394 AFB00010 */  sw        $s0, 0x10($sp)
/* AFDED8 80240398 8E30000C */  lw        $s0, 0xc($s1)
/* AFDEDC 8024039C 8E050000 */  lw        $a1, ($s0)
/* AFDEE0 802403A0 0C0B1EAF */  jal       get_variable
/* AFDEE4 802403A4 26100004 */   addiu    $s0, $s0, 4
/* AFDEE8 802403A8 0220202D */  daddu     $a0, $s1, $zero
/* AFDEEC 802403AC 8E050000 */  lw        $a1, ($s0)
/* AFDEF0 802403B0 0C0B1EAF */  jal       get_variable
/* AFDEF4 802403B4 0040802D */   daddu    $s0, $v0, $zero
/* AFDEF8 802403B8 44820000 */  mtc1      $v0, $f0
/* AFDEFC 802403BC 00000000 */  nop       
/* AFDF00 802403C0 46800020 */  cvt.s.w   $f0, $f0
/* AFDF04 802403C4 24020002 */  addiu     $v0, $zero, 2
/* AFDF08 802403C8 00501804 */  sllv      $v1, $s0, $v0
/* AFDF0C 802403CC 00701821 */  addu      $v1, $v1, $s0
/* AFDF10 802403D0 00431804 */  sllv      $v1, $v1, $v0
/* AFDF14 802403D4 00701823 */  subu      $v1, $v1, $s0
/* AFDF18 802403D8 000320C0 */  sll       $a0, $v1, 3
/* AFDF1C 802403DC 00641821 */  addu      $v1, $v1, $a0
/* AFDF20 802403E0 000318C0 */  sll       $v1, $v1, 3
/* AFDF24 802403E4 3C01800B */  lui       $at, 0x800b
/* AFDF28 802403E8 00230821 */  addu      $at, $at, $v1
/* AFDF2C 802403EC E4201D98 */  swc1      $f0, 0x1d98($at)
/* AFDF30 802403F0 8FBF0018 */  lw        $ra, 0x18($sp)
/* AFDF34 802403F4 8FB10014 */  lw        $s1, 0x14($sp)
/* AFDF38 802403F8 8FB00010 */  lw        $s0, 0x10($sp)
/* AFDF3C 802403FC 03E00008 */  jr        $ra
/* AFDF40 80240400 27BD0020 */   addiu    $sp, $sp, 0x20
