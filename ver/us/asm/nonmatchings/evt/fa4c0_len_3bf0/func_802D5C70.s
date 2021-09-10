.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D5C70
/* FA620 802D5C70 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* FA624 802D5C74 AFBF0010 */  sw        $ra, 0x10($sp)
/* FA628 802D5C78 8C82000C */  lw        $v0, 0xc($a0)
/* FA62C 802D5C7C 0C0B1EAF */  jal       evt_get_variable
/* FA630 802D5C80 8C450000 */   lw       $a1, ($v0)
/* FA634 802D5C84 0000282D */  daddu     $a1, $zero, $zero
/* FA638 802D5C88 3C04802E */  lui       $a0, %hi(D_802DB800)
/* FA63C 802D5C8C 2484B800 */  addiu     $a0, $a0, %lo(D_802DB800)
/* FA640 802D5C90 3C03802E */  lui       $v1, %hi(D_802DB7D8)
/* FA644 802D5C94 2463B7D8 */  addiu     $v1, $v1, %lo(D_802DB7D8)
/* FA648 802D5C98 3C01802E */  lui       $at, %hi(D_802DB7D0)
/* FA64C 802D5C9C AC22B7D0 */  sw        $v0, %lo(D_802DB7D0)($at)
.L802D5CA0:
/* FA650 802D5CA0 AC600000 */  sw        $zero, ($v1)
/* FA654 802D5CA4 AC800000 */  sw        $zero, ($a0)
/* FA658 802D5CA8 24840004 */  addiu     $a0, $a0, 4
/* FA65C 802D5CAC 24A50001 */  addiu     $a1, $a1, 1
/* FA660 802D5CB0 28A2000A */  slti      $v0, $a1, 0xa
/* FA664 802D5CB4 1440FFFA */  bnez      $v0, .L802D5CA0
/* FA668 802D5CB8 24630004 */   addiu    $v1, $v1, 4
/* FA66C 802D5CBC 3C04802E */  lui       $a0, %hi(D_802D9D34)
/* FA670 802D5CC0 24849D34 */  addiu     $a0, $a0, %lo(D_802D9D34)
/* FA674 802D5CC4 24050001 */  addiu     $a1, $zero, 1
/* FA678 802D5CC8 0C0B0CF8 */  jal       start_script
/* FA67C 802D5CCC 0000302D */   daddu    $a2, $zero, $zero
/* FA680 802D5CD0 8FBF0010 */  lw        $ra, 0x10($sp)
/* FA684 802D5CD4 24020002 */  addiu     $v0, $zero, 2
/* FA688 802D5CD8 03E00008 */  jr        $ra
/* FA68C 802D5CDC 27BD0018 */   addiu    $sp, $sp, 0x18
