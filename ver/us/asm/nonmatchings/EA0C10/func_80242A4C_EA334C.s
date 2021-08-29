.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242A4C_EA334C
/* EA334C 80242A4C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EA3350 80242A50 AFBF0010 */  sw        $ra, 0x10($sp)
/* EA3354 80242A54 8C82000C */  lw        $v0, 0xc($a0)
/* EA3358 80242A58 0C0B53A3 */  jal       dead_evt_get_variable
/* EA335C 80242A5C 8C450000 */   lw       $a1, ($v0)
/* EA3360 80242A60 0040182D */  daddu     $v1, $v0, $zero
/* EA3364 80242A64 10600012 */  beqz      $v1, .L80242AB0
/* EA3368 80242A68 0000202D */   daddu    $a0, $zero, $zero
/* EA336C 80242A6C 8C620000 */  lw        $v0, ($v1)
/* EA3370 80242A70 5040000A */  beql      $v0, $zero, .L80242A9C
/* EA3374 80242A74 00041080 */   sll      $v0, $a0, 2
/* EA3378 80242A78 3C058024 */  lui       $a1, %hi(D_802466D0)
/* EA337C 80242A7C 24A566D0 */  addiu     $a1, $a1, %lo(D_802466D0)
.L80242A80:
/* EA3380 80242A80 24630004 */  addiu     $v1, $v1, 4
/* EA3384 80242A84 24840001 */  addiu     $a0, $a0, 1
/* EA3388 80242A88 ACA20000 */  sw        $v0, ($a1)
/* EA338C 80242A8C 8C620000 */  lw        $v0, ($v1)
/* EA3390 80242A90 1440FFFB */  bnez      $v0, .L80242A80
/* EA3394 80242A94 24A50004 */   addiu    $a1, $a1, 4
/* EA3398 80242A98 00041080 */  sll       $v0, $a0, 2
.L80242A9C:
/* EA339C 80242A9C 3C018024 */  lui       $at, %hi(D_802466D0)
/* EA33A0 80242AA0 00220821 */  addu      $at, $at, $v0
/* EA33A4 80242AA4 AC2066D0 */  sw        $zero, %lo(D_802466D0)($at)
/* EA33A8 80242AA8 08090AB6 */  j         .L80242AD8
/* EA33AC 80242AAC 00000000 */   nop
.L80242AB0:
/* EA33B0 80242AB0 3C038024 */  lui       $v1, %hi(D_802466D0)
/* EA33B4 80242AB4 246366D0 */  addiu     $v1, $v1, %lo(D_802466D0)
/* EA33B8 80242AB8 0060282D */  daddu     $a1, $v1, $zero
.L80242ABC:
/* EA33BC 80242ABC 24820010 */  addiu     $v0, $a0, 0x10
/* EA33C0 80242AC0 AC620000 */  sw        $v0, ($v1)
/* EA33C4 80242AC4 24630004 */  addiu     $v1, $v1, 4
/* EA33C8 80242AC8 24840001 */  addiu     $a0, $a0, 1
/* EA33CC 80242ACC 28820070 */  slti      $v0, $a0, 0x70
/* EA33D0 80242AD0 1440FFFA */  bnez      $v0, .L80242ABC
/* EA33D4 80242AD4 ACA001C0 */   sw       $zero, 0x1c0($a1)
.L80242AD8:
/* EA33D8 80242AD8 8FBF0010 */  lw        $ra, 0x10($sp)
/* EA33DC 80242ADC 24020002 */  addiu     $v0, $zero, 2
/* EA33E0 80242AE0 03E00008 */  jr        $ra
/* EA33E4 80242AE4 27BD0018 */   addiu    $sp, $sp, 0x18
