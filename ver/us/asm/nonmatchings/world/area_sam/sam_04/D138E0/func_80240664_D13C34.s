.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240664_D13C34
/* D13C34 80240664 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D13C38 80240668 AFBF0010 */  sw        $ra, 0x10($sp)
/* D13C3C 8024066C 8C82000C */  lw        $v0, 0xc($a0)
/* D13C40 80240670 0C0B1EAF */  jal       get_variable
/* D13C44 80240674 8C450000 */   lw       $a1, ($v0)
/* D13C48 80240678 0040182D */  daddu     $v1, $v0, $zero
/* D13C4C 8024067C 10600012 */  beqz      $v1, .L802406C8
/* D13C50 80240680 0000202D */   daddu    $a0, $zero, $zero
/* D13C54 80240684 8C620000 */  lw        $v0, ($v1)
/* D13C58 80240688 5040000A */  beql      $v0, $zero, .L802406B4
/* D13C5C 8024068C 00041080 */   sll      $v0, $a0, 2
/* D13C60 80240690 3C058024 */  lui       $a1, %hi(D_802453D8)
/* D13C64 80240694 24A553D8 */  addiu     $a1, $a1, %lo(D_802453D8)
.L80240698:
/* D13C68 80240698 24630004 */  addiu     $v1, $v1, 4
/* D13C6C 8024069C 24840001 */  addiu     $a0, $a0, 1
/* D13C70 802406A0 ACA20000 */  sw        $v0, ($a1)
/* D13C74 802406A4 8C620000 */  lw        $v0, ($v1)
/* D13C78 802406A8 1440FFFB */  bnez      $v0, .L80240698
/* D13C7C 802406AC 24A50004 */   addiu    $a1, $a1, 4
/* D13C80 802406B0 00041080 */  sll       $v0, $a0, 2
.L802406B4:
/* D13C84 802406B4 3C018024 */  lui       $at, %hi(D_802453D8)
/* D13C88 802406B8 00220821 */  addu      $at, $at, $v0
/* D13C8C 802406BC AC2053D8 */  sw        $zero, %lo(D_802453D8)($at)
/* D13C90 802406C0 080901BC */  j         .L802406F0
/* D13C94 802406C4 00000000 */   nop
.L802406C8:
/* D13C98 802406C8 3C038024 */  lui       $v1, %hi(D_802453D8)
/* D13C9C 802406CC 246353D8 */  addiu     $v1, $v1, %lo(D_802453D8)
/* D13CA0 802406D0 0060282D */  daddu     $a1, $v1, $zero
.L802406D4:
/* D13CA4 802406D4 24820080 */  addiu     $v0, $a0, 0x80
/* D13CA8 802406D8 AC620000 */  sw        $v0, ($v1)
/* D13CAC 802406DC 24630004 */  addiu     $v1, $v1, 4
/* D13CB0 802406E0 24840001 */  addiu     $a0, $a0, 1
/* D13CB4 802406E4 2882005B */  slti      $v0, $a0, 0x5b
/* D13CB8 802406E8 1440FFFA */  bnez      $v0, .L802406D4
/* D13CBC 802406EC ACA0016C */   sw       $zero, 0x16c($a1)
.L802406F0:
/* D13CC0 802406F0 8FBF0010 */  lw        $ra, 0x10($sp)
/* D13CC4 802406F4 24020002 */  addiu     $v0, $zero, 2
/* D13CC8 802406F8 03E00008 */  jr        $ra
/* D13CCC 802406FC 27BD0018 */   addiu    $sp, $sp, 0x18
