.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403F0_BA4B70
/* BA4B70 802403F0 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* BA4B74 802403F4 AFB10024 */  sw        $s1, 0x24($sp)
/* BA4B78 802403F8 0080882D */  daddu     $s1, $a0, $zero
/* BA4B7C 802403FC AFBF0028 */  sw        $ra, 0x28($sp)
/* BA4B80 80240400 AFB00020 */  sw        $s0, 0x20($sp)
/* BA4B84 80240404 F7B60038 */  sdc1      $f22, 0x38($sp)
/* BA4B88 80240408 F7B40030 */  sdc1      $f20, 0x30($sp)
/* BA4B8C 8024040C 8E30000C */  lw        $s0, 0xc($s1)
/* BA4B90 80240410 8E050000 */  lw        $a1, ($s0)
/* BA4B94 80240414 0C0B1EAF */  jal       get_variable
/* BA4B98 80240418 26100004 */   addiu    $s0, $s0, 4
/* BA4B9C 8024041C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* BA4BA0 80240420 0040202D */   daddu    $a0, $v0, $zero
/* BA4BA4 80240424 0C046B4C */  jal       get_model_from_list_index
/* BA4BA8 80240428 0040202D */   daddu    $a0, $v0, $zero
/* BA4BAC 8024042C 8C420008 */  lw        $v0, 8($v0)
/* BA4BB0 80240430 27A50010 */  addiu     $a1, $sp, 0x10
/* BA4BB4 80240434 8C420004 */  lw        $v0, 4($v0)
/* BA4BB8 80240438 27A60014 */  addiu     $a2, $sp, 0x14
/* BA4BBC 8024043C 8C440000 */  lw        $a0, ($v0)
/* BA4BC0 80240440 0C09001C */  jal       func_80240070_BA47F0
/* BA4BC4 80240444 27A70018 */   addiu    $a3, $sp, 0x18
/* BA4BC8 80240448 C7A00010 */  lwc1      $f0, 0x10($sp)
/* BA4BCC 8024044C 3C014480 */  lui       $at, 0x4480
/* BA4BD0 80240450 4481A000 */  mtc1      $at, $f20
/* BA4BD4 80240454 00000000 */  nop
/* BA4BD8 80240458 46140002 */  mul.s     $f0, $f0, $f20
/* BA4BDC 8024045C 00000000 */  nop
/* BA4BE0 80240460 3C01CD5B */  lui       $at, 0xcd5b
/* BA4BE4 80240464 34215858 */  ori       $at, $at, 0x5858
/* BA4BE8 80240468 4481B000 */  mtc1      $at, $f22
/* BA4BEC 8024046C 00000000 */  nop
/* BA4BF0 80240470 46160000 */  add.s     $f0, $f0, $f22
/* BA4BF4 80240474 8E050000 */  lw        $a1, ($s0)
/* BA4BF8 80240478 4600008D */  trunc.w.s $f2, $f0
/* BA4BFC 8024047C 44061000 */  mfc1      $a2, $f2
/* BA4C00 80240480 0C0B2026 */  jal       evt_set_variable
/* BA4C04 80240484 0220202D */   daddu    $a0, $s1, $zero
/* BA4C08 80240488 C7A00014 */  lwc1      $f0, 0x14($sp)
/* BA4C0C 8024048C 46140002 */  mul.s     $f0, $f0, $f20
/* BA4C10 80240490 00000000 */  nop
/* BA4C14 80240494 26100004 */  addiu     $s0, $s0, 4
/* BA4C18 80240498 46160000 */  add.s     $f0, $f0, $f22
/* BA4C1C 8024049C 8E050000 */  lw        $a1, ($s0)
/* BA4C20 802404A0 4600008D */  trunc.w.s $f2, $f0
/* BA4C24 802404A4 44061000 */  mfc1      $a2, $f2
/* BA4C28 802404A8 0C0B2026 */  jal       evt_set_variable
/* BA4C2C 802404AC 0220202D */   daddu    $a0, $s1, $zero
/* BA4C30 802404B0 C7A00018 */  lwc1      $f0, 0x18($sp)
/* BA4C34 802404B4 46140002 */  mul.s     $f0, $f0, $f20
/* BA4C38 802404B8 00000000 */  nop
/* BA4C3C 802404BC 26100004 */  addiu     $s0, $s0, 4
/* BA4C40 802404C0 46160000 */  add.s     $f0, $f0, $f22
/* BA4C44 802404C4 8E050000 */  lw        $a1, ($s0)
/* BA4C48 802404C8 4600008D */  trunc.w.s $f2, $f0
/* BA4C4C 802404CC 44061000 */  mfc1      $a2, $f2
/* BA4C50 802404D0 0C0B2026 */  jal       evt_set_variable
/* BA4C54 802404D4 0220202D */   daddu    $a0, $s1, $zero
/* BA4C58 802404D8 8FBF0028 */  lw        $ra, 0x28($sp)
/* BA4C5C 802404DC 8FB10024 */  lw        $s1, 0x24($sp)
/* BA4C60 802404E0 8FB00020 */  lw        $s0, 0x20($sp)
/* BA4C64 802404E4 D7B60038 */  ldc1      $f22, 0x38($sp)
/* BA4C68 802404E8 D7B40030 */  ldc1      $f20, 0x30($sp)
/* BA4C6C 802404EC 24020002 */  addiu     $v0, $zero, 2
/* BA4C70 802404F0 03E00008 */  jr        $ra
/* BA4C74 802404F4 27BD0040 */   addiu    $sp, $sp, 0x40
