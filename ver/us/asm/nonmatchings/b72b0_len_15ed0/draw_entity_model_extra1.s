.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel draw_entity_model_extra1
/* B8788 80122088 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* B878C 8012208C 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* B8790 80122090 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* B8794 80122094 AFBF0020 */  sw        $ra, 0x20($sp)
/* B8798 80122098 80420070 */  lb        $v0, 0x70($v0)
/* B879C 8012209C 10400004 */  beqz      $v0, .L801220B0
/* B87A0 801220A0 27A80010 */   addiu    $t0, $sp, 0x10
/* B87A4 801220A4 30820800 */  andi      $v0, $a0, 0x800
/* B87A8 801220A8 10400034 */  beqz      $v0, .L8012217C
/* B87AC 801220AC 00000000 */   nop
.L801220B0:
/* B87B0 801220B0 2402F7FF */  addiu     $v0, $zero, -0x801
/* B87B4 801220B4 00822024 */  and       $a0, $a0, $v0
/* B87B8 801220B8 3C038015 */  lui       $v1, %hi(gCurrentEntityModelList)
/* B87BC 801220BC 8C634370 */  lw        $v1, %lo(gCurrentEntityModelList)($v1)
/* B87C0 801220C0 00041080 */  sll       $v0, $a0, 2
/* B87C4 801220C4 00431021 */  addu      $v0, $v0, $v1
/* B87C8 801220C8 8C470000 */  lw        $a3, ($v0)
/* B87CC 801220CC 10E0002B */  beqz      $a3, .L8012217C
/* B87D0 801220D0 00000000 */   nop
/* B87D4 801220D4 8CE60000 */  lw        $a2, ($a3)
/* B87D8 801220D8 10C00028 */  beqz      $a2, .L8012217C
/* B87DC 801220DC 30C20100 */   andi     $v0, $a2, 0x100
/* B87E0 801220E0 14400026 */  bnez      $v0, .L8012217C
/* B87E4 801220E4 30C20020 */   andi     $v0, $a2, 0x20
/* B87E8 801220E8 14400024 */  bnez      $v0, .L8012217C
/* B87EC 801220EC 30C20040 */   andi     $v0, $a2, 0x40
/* B87F0 801220F0 14400022 */  bnez      $v0, .L8012217C
/* B87F4 801220F4 24020001 */   addiu    $v0, $zero, 1
/* B87F8 801220F8 3C03800A */  lui       $v1, %hi(D_8009A634)
/* B87FC 801220FC 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* B8800 80122100 00621004 */  sllv      $v0, $v0, $v1
/* B8804 80122104 00C21024 */  and       $v0, $a2, $v0
/* B8808 80122108 1040001C */  beqz      $v0, .L8012217C
/* B880C 8012210C 34C20200 */   ori      $v0, $a2, 0x200
/* B8810 80122110 ACE20000 */  sw        $v0, ($a3)
/* B8814 80122114 24E20018 */  addiu     $v0, $a3, 0x18
/* B8818 80122118 24A30040 */  addiu     $v1, $a1, 0x40
.L8012211C:
/* B881C 8012211C 8CA90000 */  lw        $t1, ($a1)
/* B8820 80122120 8CAA0004 */  lw        $t2, 4($a1)
/* B8824 80122124 8CAB0008 */  lw        $t3, 8($a1)
/* B8828 80122128 8CAC000C */  lw        $t4, 0xc($a1)
/* B882C 8012212C AC490000 */  sw        $t1, ($v0)
/* B8830 80122130 AC4A0004 */  sw        $t2, 4($v0)
/* B8834 80122134 AC4B0008 */  sw        $t3, 8($v0)
/* B8838 80122138 AC4C000C */  sw        $t4, 0xc($v0)
/* B883C 8012213C 24A50010 */  addiu     $a1, $a1, 0x10
/* B8840 80122140 14A3FFF6 */  bne       $a1, $v1, .L8012211C
/* B8844 80122144 24420010 */   addiu    $v0, $v0, 0x10
/* B8848 80122148 80E30004 */  lb        $v1, 4($a3)
/* B884C 8012214C 3C028012 */  lui       $v0, %hi(appendGfx_entity_model)
/* B8850 80122150 24421184 */  addiu     $v0, $v0, %lo(appendGfx_entity_model)
/* B8854 80122154 ACE0005C */  sw        $zero, 0x5c($a3)
/* B8858 80122158 AD070008 */  sw        $a3, 8($t0)
/* B885C 8012215C AD02000C */  sw        $v0, 0xc($t0)
/* B8860 80122160 AD030000 */  sw        $v1, ($t0)
/* B8864 80122164 8CE20000 */  lw        $v0, ($a3)
/* B8868 80122168 0100202D */  daddu     $a0, $t0, $zero
/* B886C 8012216C 3042F000 */  andi      $v0, $v0, 0xf000
/* B8870 80122170 00021202 */  srl       $v0, $v0, 8
/* B8874 80122174 0C047644 */  jal       queue_render_task
/* B8878 80122178 AD020004 */   sw       $v0, 4($t0)
.L8012217C:
/* B887C 8012217C 8FBF0020 */  lw        $ra, 0x20($sp)
/* B8880 80122180 03E00008 */  jr        $ra
/* B8884 80122184 27BD0028 */   addiu    $sp, $sp, 0x28
