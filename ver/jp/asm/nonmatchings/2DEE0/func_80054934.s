.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80054934
/* 2FD34 80054934 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 2FD38 80054938 0080182D */  daddu     $v1, $a0, $zero
/* 2FD3C 8005493C 00A0202D */  daddu     $a0, $a1, $zero
/* 2FD40 80054940 3C02800A */  lui       $v0, %hi(D_8009A5A0)
/* 2FD44 80054944 8C42A5A0 */  lw        $v0, %lo(D_8009A5A0)($v0)
/* 2FD48 80054948 AFBF0014 */  sw        $ra, 0x14($sp)
/* 2FD4C 8005494C AFB00010 */  sw        $s0, 0x10($sp)
/* 2FD50 80054950 8C500004 */  lw        $s0, 4($v0)
/* 2FD54 80054954 0C0150FD */  jal       func_800543F4
/* 2FD58 80054958 0060282D */   daddu    $a1, $v1, $zero
/* 2FD5C 8005495C 0040182D */  daddu     $v1, $v0, $zero
/* 2FD60 80054960 10600007 */  beqz      $v1, .L80054980
/* 2FD64 80054964 00000000 */   nop
/* 2FD68 80054968 0000202D */  daddu     $a0, $zero, $zero
.L8005496C:
/* 2FD6C 8005496C AC700000 */  sw        $s0, ($v1)
/* 2FD70 80054970 24840001 */  addiu     $a0, $a0, 1
/* 2FD74 80054974 2C820010 */  sltiu     $v0, $a0, 0x10
/* 2FD78 80054978 1440FFFC */  bnez      $v0, .L8005496C
/* 2FD7C 8005497C 24630004 */   addiu    $v1, $v1, 4
.L80054980:
/* 2FD80 80054980 8FBF0014 */  lw        $ra, 0x14($sp)
/* 2FD84 80054984 8FB00010 */  lw        $s0, 0x10($sp)
/* 2FD88 80054988 03E00008 */  jr        $ra
/* 2FD8C 8005498C 27BD0018 */   addiu    $sp, $sp, 0x18
