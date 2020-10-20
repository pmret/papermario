.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240790_C71C10
/* C71C10 80240790 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C71C14 80240794 AFB00010 */  sw        $s0, 0x10($sp)
/* C71C18 80240798 3C108024 */  lui       $s0, 0x8024
/* C71C1C 8024079C 26104BB0 */  addiu     $s0, $s0, 0x4bb0
/* C71C20 802407A0 AFBF0018 */  sw        $ra, 0x18($sp)
/* C71C24 802407A4 AFB10014 */  sw        $s1, 0x14($sp)
/* C71C28 802407A8 8E020000 */  lw        $v0, ($s0)
/* C71C2C 802407AC 14400010 */  bnez      $v0, .L802407F0
/* C71C30 802407B0 0080882D */   daddu    $s1, $a0, $zero
/* C71C34 802407B4 0C00AB39 */  jal       heap_malloc
/* C71C38 802407B8 24040040 */   addiu    $a0, $zero, 0x40
/* C71C3C 802407BC AE020000 */  sw        $v0, ($s0)
/* C71C40 802407C0 0000182D */  daddu     $v1, $zero, $zero
/* C71C44 802407C4 0040282D */  daddu     $a1, $v0, $zero
/* C71C48 802407C8 0220202D */  daddu     $a0, $s1, $zero
.L802407CC:
/* C71C4C 802407CC 8C820084 */  lw        $v0, 0x84($a0)
/* C71C50 802407D0 24840004 */  addiu     $a0, $a0, 4
/* C71C54 802407D4 24630001 */  addiu     $v1, $v1, 1
/* C71C58 802407D8 ACA20000 */  sw        $v0, ($a1)
/* C71C5C 802407DC 28620010 */  slti      $v0, $v1, 0x10
/* C71C60 802407E0 1440FFFA */  bnez      $v0, .L802407CC
/* C71C64 802407E4 24A50004 */   addiu    $a1, $a1, 4
/* C71C68 802407E8 0809020B */  j         .L8024082C
/* C71C6C 802407EC 00000000 */   nop      
.L802407F0:
/* C71C70 802407F0 0000182D */  daddu     $v1, $zero, $zero
/* C71C74 802407F4 0040282D */  daddu     $a1, $v0, $zero
/* C71C78 802407F8 0220202D */  daddu     $a0, $s1, $zero
.L802407FC:
/* C71C7C 802407FC 8CA20000 */  lw        $v0, ($a1)
/* C71C80 80240800 24A50004 */  addiu     $a1, $a1, 4
/* C71C84 80240804 24630001 */  addiu     $v1, $v1, 1
/* C71C88 80240808 AC820084 */  sw        $v0, 0x84($a0)
/* C71C8C 8024080C 28620010 */  slti      $v0, $v1, 0x10
/* C71C90 80240810 1440FFFA */  bnez      $v0, .L802407FC
/* C71C94 80240814 24840004 */   addiu    $a0, $a0, 4
/* C71C98 80240818 3C108024 */  lui       $s0, 0x8024
/* C71C9C 8024081C 26104BB0 */  addiu     $s0, $s0, 0x4bb0
/* C71CA0 80240820 0C00AB4B */  jal       heap_free
/* C71CA4 80240824 8E040000 */   lw       $a0, ($s0)
/* C71CA8 80240828 AE000000 */  sw        $zero, ($s0)
.L8024082C:
/* C71CAC 8024082C 8FBF0018 */  lw        $ra, 0x18($sp)
/* C71CB0 80240830 8FB10014 */  lw        $s1, 0x14($sp)
/* C71CB4 80240834 8FB00010 */  lw        $s0, 0x10($sp)
/* C71CB8 80240838 24020002 */  addiu     $v0, $zero, 2
/* C71CBC 8024083C 03E00008 */  jr        $ra
/* C71CC0 80240840 27BD0020 */   addiu    $sp, $sp, 0x20
