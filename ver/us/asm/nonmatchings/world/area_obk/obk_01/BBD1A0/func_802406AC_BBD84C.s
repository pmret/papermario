.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406AC_BBD84C
/* BBD84C 802406AC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BBD850 802406B0 AFB00010 */  sw        $s0, 0x10($sp)
/* BBD854 802406B4 0080802D */  daddu     $s0, $a0, $zero
/* BBD858 802406B8 AFBF0014 */  sw        $ra, 0x14($sp)
/* BBD85C 802406BC 10A00005 */  beqz      $a1, .L802406D4
/* BBD860 802406C0 8E02000C */   lw       $v0, 0xc($s0)
/* BBD864 802406C4 0C0B1EAF */  jal       evt_get_variable
/* BBD868 802406C8 8C450000 */   lw       $a1, ($v0)
/* BBD86C 802406CC 8C420000 */  lw        $v0, ($v0)
/* BBD870 802406D0 AE020074 */  sw        $v0, 0x74($s0)
.L802406D4:
/* BBD874 802406D4 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* BBD878 802406D8 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* BBD87C 802406DC 8C420010 */  lw        $v0, 0x10($v0)
/* BBD880 802406E0 8E050074 */  lw        $a1, 0x74($s0)
/* BBD884 802406E4 30428000 */  andi      $v0, $v0, 0x8000
/* BBD888 802406E8 1040000D */  beqz      $v0, .L80240720
/* BBD88C 802406EC 0000102D */   daddu    $v0, $zero, $zero
/* BBD890 802406F0 8CA20000 */  lw        $v0, ($a1)
/* BBD894 802406F4 30420004 */  andi      $v0, $v0, 4
/* BBD898 802406F8 10400003 */  beqz      $v0, .L80240708
/* BBD89C 802406FC 24020001 */   addiu    $v0, $zero, 1
/* BBD8A0 80240700 080901C3 */  j         .L8024070C
/* BBD8A4 80240704 AE020084 */   sw       $v0, 0x84($s0)
.L80240708:
/* BBD8A8 80240708 AE000084 */  sw        $zero, 0x84($s0)
.L8024070C:
/* BBD8AC 8024070C 24020002 */  addiu     $v0, $zero, 2
/* BBD8B0 80240710 8CA30000 */  lw        $v1, ($a1)
/* BBD8B4 80240714 2404FFFD */  addiu     $a0, $zero, -3
/* BBD8B8 80240718 00641824 */  and       $v1, $v1, $a0
/* BBD8BC 8024071C ACA30000 */  sw        $v1, ($a1)
.L80240720:
/* BBD8C0 80240720 8FBF0014 */  lw        $ra, 0x14($sp)
/* BBD8C4 80240724 8FB00010 */  lw        $s0, 0x10($sp)
/* BBD8C8 80240728 03E00008 */  jr        $ra
/* BBD8CC 8024072C 27BD0018 */   addiu    $sp, $sp, 0x18
