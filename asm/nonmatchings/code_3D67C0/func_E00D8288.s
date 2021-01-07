.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00D8288
/* 3D6A48 E00D8288 0080402D */  daddu     $t0, $a0, $zero
/* 3D6A4C E00D828C 05010002 */  bgez      $t0, .LE00D8298
/* 3D6A50 E00D8290 00A0482D */   daddu    $t1, $a1, $zero
/* 3D6A54 E00D8294 0000402D */  daddu     $t0, $zero, $zero
.LE00D8298:
/* 3D6A58 E00D8298 05220001 */  bltzl     $t1, .LE00D82A0
/* 3D6A5C E00D829C 0000482D */   daddu    $t1, $zero, $zero
.LE00D82A0:
/* 3D6A60 E00D82A0 04C20001 */  bltzl     $a2, .LE00D82A8
/* 3D6A64 E00D82A4 0000302D */   daddu    $a2, $zero, $zero
.LE00D82A8:
/* 3D6A68 E00D82A8 04E20001 */  bltzl     $a3, .LE00D82B0
/* 3D6A6C E00D82AC 0000382D */   daddu    $a3, $zero, $zero
.LE00D82B0:
/* 3D6A70 E00D82B0 29020140 */  slti      $v0, $t0, 0x140
/* 3D6A74 E00D82B4 50400001 */  beql      $v0, $zero, .LE00D82BC
/* 3D6A78 E00D82B8 2408013F */   addiu    $t0, $zero, 0x13f
.LE00D82BC:
/* 3D6A7C E00D82BC 292200F0 */  slti      $v0, $t1, 0xf0
/* 3D6A80 E00D82C0 50400001 */  beql      $v0, $zero, .LE00D82C8
/* 3D6A84 E00D82C4 240900EF */   addiu    $t1, $zero, 0xef
.LE00D82C8:
/* 3D6A88 E00D82C8 28C20140 */  slti      $v0, $a2, 0x140
/* 3D6A8C E00D82CC 50400001 */  beql      $v0, $zero, .LE00D82D4
/* 3D6A90 E00D82D0 2406013F */   addiu    $a2, $zero, 0x13f
.LE00D82D4:
/* 3D6A94 E00D82D4 28E200F0 */  slti      $v0, $a3, 0xf0
/* 3D6A98 E00D82D8 50400001 */  beql      $v0, $zero, .LE00D82E0
/* 3D6A9C E00D82DC 240700EF */   addiu    $a3, $zero, 0xef
.LE00D82E0:
/* 3D6AA0 E00D82E0 3C03800A */  lui       $v1, %hi(D_8009A66C)
/* 3D6AA4 E00D82E4 2463A66C */  addiu     $v1, $v1, %lo(D_8009A66C)
/* 3D6AA8 E00D82E8 30C403FF */  andi      $a0, $a2, 0x3ff
/* 3D6AAC E00D82EC 8C620000 */  lw        $v0, ($v1)
/* 3D6AB0 E00D82F0 00042380 */  sll       $a0, $a0, 0xe
/* 3D6AB4 E00D82F4 0040282D */  daddu     $a1, $v0, $zero
/* 3D6AB8 E00D82F8 24420008 */  addiu     $v0, $v0, 8
/* 3D6ABC E00D82FC AC620000 */  sw        $v0, ($v1)
/* 3D6AC0 E00D8300 30E203FF */  andi      $v0, $a3, 0x3ff
/* 3D6AC4 E00D8304 00021080 */  sll       $v0, $v0, 2
/* 3D6AC8 E00D8308 3C03F600 */  lui       $v1, 0xf600
/* 3D6ACC E00D830C 00431025 */  or        $v0, $v0, $v1
/* 3D6AD0 E00D8310 00822025 */  or        $a0, $a0, $v0
/* 3D6AD4 E00D8314 310303FF */  andi      $v1, $t0, 0x3ff
/* 3D6AD8 E00D8318 00031B80 */  sll       $v1, $v1, 0xe
/* 3D6ADC E00D831C 312203FF */  andi      $v0, $t1, 0x3ff
/* 3D6AE0 E00D8320 00021080 */  sll       $v0, $v0, 2
/* 3D6AE4 E00D8324 00621825 */  or        $v1, $v1, $v0
/* 3D6AE8 E00D8328 ACA40000 */  sw        $a0, ($a1)
/* 3D6AEC E00D832C 03E00008 */  jr        $ra
/* 3D6AF0 E00D8330 ACA30004 */   sw       $v1, 4($a1)
