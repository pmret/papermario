.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242898_DF9298
/* DF9298 80242898 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* DF929C 8024289C AFB00010 */  sw        $s0, 0x10($sp)
/* DF92A0 802428A0 0080802D */  daddu     $s0, $a0, $zero
/* DF92A4 802428A4 AFBF0014 */  sw        $ra, 0x14($sp)
/* DF92A8 802428A8 10A00006 */  beqz      $a1, .L802428C4
/* DF92AC 802428AC 8E02000C */   lw       $v0, 0xc($s0)
/* DF92B0 802428B0 0C0B1EAF */  jal       get_variable
/* DF92B4 802428B4 8C450000 */   lw       $a1, ($v0)
/* DF92B8 802428B8 0C00EABB */  jal       get_npc_unsafe
/* DF92BC 802428BC 0040202D */   daddu    $a0, $v0, $zero
/* DF92C0 802428C0 AE020074 */  sw        $v0, 0x74($s0)
.L802428C4:
/* DF92C4 802428C4 8E030074 */  lw        $v1, 0x74($s0)
/* DF92C8 802428C8 3C013F2A */  lui       $at, 0x3f2a
/* DF92CC 802428CC 3421AAAB */  ori       $at, $at, 0xaaab
/* DF92D0 802428D0 44811000 */  mtc1      $at, $f2
/* DF92D4 802428D4 C4600038 */  lwc1      $f0, 0x38($v1)
/* DF92D8 802428D8 46020000 */  add.s     $f0, $f0, $f2
/* DF92DC 802428DC E4600038 */  swc1      $f0, 0x38($v1)
/* DF92E0 802428E0 8FBF0014 */  lw        $ra, 0x14($sp)
/* DF92E4 802428E4 8FB00010 */  lw        $s0, 0x10($sp)
/* DF92E8 802428E8 0000102D */  daddu     $v0, $zero, $zero
/* DF92EC 802428EC 03E00008 */  jr        $ra
/* DF92F0 802428F0 27BD0018 */   addiu    $sp, $sp, 0x18
/* DF92F4 802428F4 00000000 */  nop       
/* DF92F8 802428F8 00000000 */  nop       
/* DF92FC 802428FC 00000000 */  nop       
