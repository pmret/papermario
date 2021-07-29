.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_spirits_update
/* 140B40 8024D800 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 140B44 8024D804 AFB50024 */  sw        $s5, 0x24($sp)
/* 140B48 8024D808 0080A82D */  daddu     $s5, $a0, $zero
/* 140B4C 8024D80C AFBF0028 */  sw        $ra, 0x28($sp)
/* 140B50 8024D810 AFB40020 */  sw        $s4, 0x20($sp)
/* 140B54 8024D814 AFB3001C */  sw        $s3, 0x1c($sp)
/* 140B58 8024D818 AFB20018 */  sw        $s2, 0x18($sp)
/* 140B5C 8024D81C AFB10014 */  sw        $s1, 0x14($sp)
/* 140B60 8024D820 0C039D59 */  jal       get_player_data
/* 140B64 8024D824 AFB00010 */   sw       $s0, 0x10($sp)
/* 140B68 8024D828 0000902D */  daddu     $s2, $zero, $zero
/* 140B6C 8024D82C 3C038027 */  lui       $v1, %hi(D_802706FC)
/* 140B70 8024D830 8C6306FC */  lw        $v1, %lo(D_802706FC)($v1)
/* 140B74 8024D834 1860001F */  blez      $v1, .L8024D8B4
/* 140B78 8024D838 0040982D */   daddu    $s3, $v0, $zero
/* 140B7C 8024D83C 24140005 */  addiu     $s4, $zero, 5
/* 140B80 8024D840 3C118025 */  lui       $s1, %hi(D_8024F8C0)
/* 140B84 8024D844 2631F8C0 */  addiu     $s1, $s1, %lo(D_8024F8C0)
/* 140B88 8024D848 3C108027 */  lui       $s0, %hi(D_802706C0)
/* 140B8C 8024D84C 261006C0 */  addiu     $s0, $s0, %lo(D_802706C0)
.L8024D850:
/* 140B90 8024D850 8262028E */  lb        $v0, 0x28e($s3)
/* 140B94 8024D854 0242102A */  slt       $v0, $s2, $v0
/* 140B98 8024D858 1040000B */  beqz      $v0, .L8024D888
/* 140B9C 8024D85C 00000000 */   nop
/* 140BA0 8024D860 3C028027 */  lui       $v0, %hi(gPauseMenuCurrentTab)
/* 140BA4 8024D864 804200D4 */  lb        $v0, %lo(gPauseMenuCurrentTab)($v0)
/* 140BA8 8024D868 14540007 */  bne       $v0, $s4, .L8024D888
/* 140BAC 8024D86C 00000000 */   nop
/* 140BB0 8024D870 92A20003 */  lbu       $v0, 3($s5)
/* 140BB4 8024D874 16420004 */  bne       $s2, $v0, .L8024D888
/* 140BB8 8024D878 00000000 */   nop
/* 140BBC 8024D87C 8E040000 */  lw        $a0, ($s0)
/* 140BC0 8024D880 08093624 */  j         .L8024D890
/* 140BC4 8024D884 8E250004 */   lw       $a1, 4($s1)
.L8024D888:
/* 140BC8 8024D888 8E040000 */  lw        $a0, ($s0)
/* 140BCC 8024D88C 8E250000 */  lw        $a1, ($s1)
.L8024D890:
/* 140BD0 8024D890 3C063F80 */  lui       $a2, 0x3f80
/* 140BD4 8024D894 0C0B78AB */  jal       spr_update_sprite
/* 140BD8 8024D898 26310010 */   addiu    $s1, $s1, 0x10
/* 140BDC 8024D89C 3C028027 */  lui       $v0, %hi(D_802706FC)
/* 140BE0 8024D8A0 8C4206FC */  lw        $v0, %lo(D_802706FC)($v0)
/* 140BE4 8024D8A4 26520001 */  addiu     $s2, $s2, 1
/* 140BE8 8024D8A8 0242102A */  slt       $v0, $s2, $v0
/* 140BEC 8024D8AC 1440FFE8 */  bnez      $v0, .L8024D850
/* 140BF0 8024D8B0 26100004 */   addiu    $s0, $s0, 4
.L8024D8B4:
/* 140BF4 8024D8B4 8FBF0028 */  lw        $ra, 0x28($sp)
/* 140BF8 8024D8B8 8FB50024 */  lw        $s5, 0x24($sp)
/* 140BFC 8024D8BC 8FB40020 */  lw        $s4, 0x20($sp)
/* 140C00 8024D8C0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 140C04 8024D8C4 8FB20018 */  lw        $s2, 0x18($sp)
/* 140C08 8024D8C8 8FB10014 */  lw        $s1, 0x14($sp)
/* 140C0C 8024D8CC 8FB00010 */  lw        $s0, 0x10($sp)
/* 140C10 8024D8D0 03E00008 */  jr        $ra
/* 140C14 8024D8D4 27BD0030 */   addiu    $sp, $sp, 0x30
