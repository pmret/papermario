.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80054C70
/* 30070 80054C70 27BDFE98 */  addiu     $sp, $sp, -0x168
/* 30074 80054C74 0080102D */  daddu     $v0, $a0, $zero
/* 30078 80054C78 27A50018 */  addiu     $a1, $sp, 0x18
/* 3007C 80054C7C AFB1015C */  sw        $s1, 0x15c($sp)
/* 30080 80054C80 0000882D */  daddu     $s1, $zero, $zero
/* 30084 80054C84 AFB20160 */  sw        $s2, 0x160($sp)
/* 30088 80054C88 3412FFFF */  ori       $s2, $zero, 0xffff
/* 3008C 80054C8C AFBF0164 */  sw        $ra, 0x164($sp)
/* 30090 80054C90 AFB00158 */  sw        $s0, 0x158($sp)
/* 30094 80054C94 8C440034 */  lw        $a0, 0x34($v0)
/* 30098 80054C98 8C460038 */  lw        $a2, 0x38($v0)
/* 3009C 80054C9C 0C0152AC */  jal       func_80054AB0
/* 300A0 80054CA0 00A0802D */   daddu    $s0, $a1, $zero
.L80054CA4:
/* 300A4 80054CA4 96020000 */  lhu       $v0, ($s0)
/* 300A8 80054CA8 1052000E */  beq       $v0, $s2, .L80054CE4
/* 300AC 80054CAC 24050030 */   addiu    $a1, $zero, 0x30
/* 300B0 80054CB0 27A60010 */  addiu     $a2, $sp, 0x10
/* 300B4 80054CB4 0040202D */  daddu     $a0, $v0, $zero
/* 300B8 80054CB8 0C01504B */  jal       func_8005412C
/* 300BC 80054CBC 26310001 */   addiu    $s1, $s1, 1
/* 300C0 80054CC0 0000282D */  daddu     $a1, $zero, $zero
/* 300C4 80054CC4 8FA40010 */  lw        $a0, 0x10($sp)
/* 300C8 80054CC8 92060002 */  lbu       $a2, 2($s0)
/* 300CC 80054CCC 92070003 */  lbu       $a3, 3($s0)
/* 300D0 80054CD0 0C01511E */  jal       func_80054478
/* 300D4 80054CD4 26100004 */   addiu    $s0, $s0, 4
/* 300D8 80054CD8 2A220050 */  slti      $v0, $s1, 0x50
/* 300DC 80054CDC 1440FFF1 */  bnez      $v0, .L80054CA4
/* 300E0 80054CE0 00000000 */   nop
.L80054CE4:
/* 300E4 80054CE4 8FBF0164 */  lw        $ra, 0x164($sp)
/* 300E8 80054CE8 8FB20160 */  lw        $s2, 0x160($sp)
/* 300EC 80054CEC 8FB1015C */  lw        $s1, 0x15c($sp)
/* 300F0 80054CF0 8FB00158 */  lw        $s0, 0x158($sp)
/* 300F4 80054CF4 03E00008 */  jr        $ra
/* 300F8 80054CF8 27BD0168 */   addiu    $sp, $sp, 0x168
/* 300FC 80054CFC 00000000 */  nop
