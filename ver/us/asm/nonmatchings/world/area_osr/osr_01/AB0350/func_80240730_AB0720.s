.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240730_AB0720
/* AB0720 80240730 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* AB0724 80240734 AFBF0010 */  sw        $ra, 0x10($sp)
/* AB0728 80240738 8C82000C */  lw        $v0, 0xc($a0)
/* AB072C 8024073C 0C0B1EAF */  jal       evt_get_variable
/* AB0730 80240740 8C450000 */   lw       $a1, ($v0)
/* AB0734 80240744 0040182D */  daddu     $v1, $v0, $zero
/* AB0738 80240748 10600012 */  beqz      $v1, .L80240794
/* AB073C 8024074C 0000202D */   daddu    $a0, $zero, $zero
/* AB0740 80240750 8C620000 */  lw        $v0, ($v1)
/* AB0744 80240754 5040000A */  beql      $v0, $zero, .L80240780
/* AB0748 80240758 00041080 */   sll      $v0, $a0, 2
/* AB074C 8024075C 3C058024 */  lui       $a1, %hi(jan_02_SetCamVfov)
/* AB0750 80240760 24A52180 */  addiu     $a1, $a1, %lo(jan_02_SetCamVfov)
.L80240764:
/* AB0754 80240764 24630004 */  addiu     $v1, $v1, 4
/* AB0758 80240768 24840001 */  addiu     $a0, $a0, 1
/* AB075C 8024076C ACA20000 */  sw        $v0, ($a1)
/* AB0760 80240770 8C620000 */  lw        $v0, ($v1)
/* AB0764 80240774 1440FFFB */  bnez      $v0, .L80240764
/* AB0768 80240778 24A50004 */   addiu    $a1, $a1, 4
/* AB076C 8024077C 00041080 */  sll       $v0, $a0, 2
.L80240780:
/* AB0770 80240780 3C018024 */  lui       $at, %hi(jan_02_SetCamVfov)
/* AB0774 80240784 00220821 */  addu      $at, $at, $v0
/* AB0778 80240788 AC202180 */  sw        $zero, %lo(jan_02_SetCamVfov)($at)
/* AB077C 8024078C 080901EF */  j         .L802407BC
/* AB0780 80240790 00000000 */   nop
.L80240794:
/* AB0784 80240794 3C038024 */  lui       $v1, %hi(jan_02_SetCamVfov)
/* AB0788 80240798 24632180 */  addiu     $v1, $v1, %lo(jan_02_SetCamVfov)
/* AB078C 8024079C 0060282D */  daddu     $a1, $v1, $zero
.L802407A0:
/* AB0790 802407A0 24820010 */  addiu     $v0, $a0, 0x10
/* AB0794 802407A4 AC620000 */  sw        $v0, ($v1)
/* AB0798 802407A8 24630004 */  addiu     $v1, $v1, 4
/* AB079C 802407AC 24840001 */  addiu     $a0, $a0, 1
/* AB07A0 802407B0 28820070 */  slti      $v0, $a0, 0x70
/* AB07A4 802407B4 1440FFFA */  bnez      $v0, .L802407A0
/* AB07A8 802407B8 ACA001C0 */   sw       $zero, 0x1c0($a1)
.L802407BC:
/* AB07AC 802407BC 8FBF0010 */  lw        $ra, 0x10($sp)
/* AB07B0 802407C0 24020002 */  addiu     $v0, $zero, 2
/* AB07B4 802407C4 03E00008 */  jr        $ra
/* AB07B8 802407C8 27BD0018 */   addiu    $sp, $sp, 0x18
