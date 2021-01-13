.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80054C84
/* 30084 80054C84 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 30088 80054C88 0080182D */  daddu     $v1, $a0, $zero
/* 3008C 80054C8C 00A0202D */  daddu     $a0, $a1, $zero
/* 30090 80054C90 3C02800A */  lui       $v0, %hi(D_8009A5C0)
/* 30094 80054C94 8C42A5C0 */  lw        $v0, %lo(D_8009A5C0)($v0)
/* 30098 80054C98 AFBF0014 */  sw        $ra, 0x14($sp)
/* 3009C 80054C9C AFB00010 */  sw        $s0, 0x10($sp)
/* 300A0 80054CA0 8C500004 */  lw        $s0, 4($v0)
/* 300A4 80054CA4 0C0151D1 */  jal       func_80054744
/* 300A8 80054CA8 0060282D */   daddu    $a1, $v1, $zero
/* 300AC 80054CAC 0040182D */  daddu     $v1, $v0, $zero
/* 300B0 80054CB0 10600007 */  beqz      $v1, .L80054CD0
/* 300B4 80054CB4 00000000 */   nop
/* 300B8 80054CB8 0000202D */  daddu     $a0, $zero, $zero
.L80054CBC:
/* 300BC 80054CBC AC700000 */  sw        $s0, ($v1)
/* 300C0 80054CC0 24840001 */  addiu     $a0, $a0, 1
/* 300C4 80054CC4 2C820010 */  sltiu     $v0, $a0, 0x10
/* 300C8 80054CC8 1440FFFC */  bnez      $v0, .L80054CBC
/* 300CC 80054CCC 24630004 */   addiu    $v1, $v1, 4
.L80054CD0:
/* 300D0 80054CD0 8FBF0014 */  lw        $ra, 0x14($sp)
/* 300D4 80054CD4 8FB00010 */  lw        $s0, 0x10($sp)
/* 300D8 80054CD8 03E00008 */  jr        $ra
/* 300DC 80054CDC 27BD0018 */   addiu    $sp, $sp, 0x18
