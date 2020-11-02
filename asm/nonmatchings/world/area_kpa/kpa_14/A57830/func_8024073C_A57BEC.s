.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024073C_A57BEC
/* A57BEC 8024073C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A57BF0 80240740 AFB10014 */  sw        $s1, 0x14($sp)
/* A57BF4 80240744 0080882D */  daddu     $s1, $a0, $zero
/* A57BF8 80240748 AFBF001C */  sw        $ra, 0x1c($sp)
/* A57BFC 8024074C AFB20018 */  sw        $s2, 0x18($sp)
/* A57C00 80240750 AFB00010 */  sw        $s0, 0x10($sp)
/* A57C04 80240754 8E30000C */  lw        $s0, 0xc($s1)
/* A57C08 80240758 8E050000 */  lw        $a1, ($s0)
/* A57C0C 8024075C 0C0B1EAF */  jal       get_variable
/* A57C10 80240760 26100004 */   addiu    $s0, $s0, 4
/* A57C14 80240764 8E050000 */  lw        $a1, ($s0)
/* A57C18 80240768 26100004 */  addiu     $s0, $s0, 4
/* A57C1C 8024076C 0220202D */  daddu     $a0, $s1, $zero
/* A57C20 80240770 0C0B1EAF */  jal       get_variable
/* A57C24 80240774 0040902D */   daddu    $s2, $v0, $zero
/* A57C28 80240778 0220202D */  daddu     $a0, $s1, $zero
/* A57C2C 8024077C 8E050000 */  lw        $a1, ($s0)
/* A57C30 80240780 0C0B1EAF */  jal       get_variable
/* A57C34 80240784 0040802D */   daddu    $s0, $v0, $zero
/* A57C38 80240788 0040202D */  daddu     $a0, $v0, $zero
/* A57C3C 8024078C 3C038016 */  lui       $v1, %hi(gCollisionStatus)
/* A57C40 80240790 2463A550 */  addiu     $v1, $v1, %lo(gCollisionStatus)
/* A57C44 80240794 84620002 */  lh        $v0, 2($v1)
/* A57C48 80240798 3C058011 */  lui       $a1, %hi(gPlayerStatus)
/* A57C4C 8024079C 24A5EFC8 */  addiu     $a1, $a1, %lo(gPlayerStatus)
/* A57C50 802407A0 10500004 */  beq       $v0, $s0, .L802407B4
/* A57C54 802407A4 00000000 */   nop      
/* A57C58 802407A8 84620004 */  lh        $v0, 4($v1)
/* A57C5C 802407AC 1450000D */  bne       $v0, $s0, .L802407E4
/* A57C60 802407B0 00000000 */   nop      
.L802407B4:
/* A57C64 802407B4 80A300B4 */  lb        $v1, 0xb4($a1)
/* A57C68 802407B8 2402000F */  addiu     $v0, $zero, 0xf
/* A57C6C 802407BC 10620009 */  beq       $v1, $v0, .L802407E4
/* A57C70 802407C0 2402000D */   addiu    $v0, $zero, 0xd
/* A57C74 802407C4 10620007 */  beq       $v1, $v0, .L802407E4
/* A57C78 802407C8 00000000 */   nop      
/* A57C7C 802407CC 14800005 */  bnez      $a0, .L802407E4
/* A57C80 802407D0 00000000 */   nop      
/* A57C84 802407D4 44920000 */  mtc1      $s2, $f0
/* A57C88 802407D8 00000000 */  nop       
/* A57C8C 802407DC 46800020 */  cvt.s.w   $f0, $f0
/* A57C90 802407E0 E4A0001C */  swc1      $f0, 0x1c($a1)
.L802407E4:
/* A57C94 802407E4 3C028011 */  lui       $v0, %hi(gPlayerData+0x12)
/* A57C98 802407E8 8042F2A2 */  lb        $v0, %lo(gPlayerData+0x12)($v0)
/* A57C9C 802407EC 1040000D */  beqz      $v0, .L80240824
/* A57CA0 802407F0 00000000 */   nop      
/* A57CA4 802407F4 0C00EABB */  jal       get_npc_unsafe
/* A57CA8 802407F8 2404FFFC */   addiu    $a0, $zero, -4
/* A57CAC 802407FC 0040182D */  daddu     $v1, $v0, $zero
/* A57CB0 80240800 84620084 */  lh        $v0, 0x84($v1)
/* A57CB4 80240804 14500007 */  bne       $v0, $s0, .L80240824
/* A57CB8 80240808 00000000 */   nop      
/* A57CBC 8024080C C4600038 */  lwc1      $f0, 0x38($v1)
/* A57CC0 80240810 44921000 */  mtc1      $s2, $f2
/* A57CC4 80240814 00000000 */  nop       
/* A57CC8 80240818 468010A0 */  cvt.s.w   $f2, $f2
/* A57CCC 8024081C 46020000 */  add.s     $f0, $f0, $f2
/* A57CD0 80240820 E4600038 */  swc1      $f0, 0x38($v1)
.L80240824:
/* A57CD4 80240824 8FBF001C */  lw        $ra, 0x1c($sp)
/* A57CD8 80240828 8FB20018 */  lw        $s2, 0x18($sp)
/* A57CDC 8024082C 8FB10014 */  lw        $s1, 0x14($sp)
/* A57CE0 80240830 8FB00010 */  lw        $s0, 0x10($sp)
/* A57CE4 80240834 24020002 */  addiu     $v0, $zero, 2
/* A57CE8 80240838 03E00008 */  jr        $ra
/* A57CEC 8024083C 27BD0020 */   addiu    $sp, $sp, 0x20
