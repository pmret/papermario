.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8013A37C
/* D0A7C 8013A37C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D0A80 8013A380 AFB10014 */  sw        $s1, 0x14($sp)
/* D0A84 8013A384 0000882D */  daddu     $s1, $zero, $zero
/* D0A88 8013A388 AFB00010 */  sw        $s0, 0x10($sp)
/* D0A8C 8013A38C 3C108015 */  lui       $s0, %hi(D_80156948)
/* D0A90 8013A390 26106948 */  addiu     $s0, $s0, %lo(D_80156948)
/* D0A94 8013A394 AFBF001C */  sw        $ra, 0x1c($sp)
/* D0A98 8013A398 AFB20018 */  sw        $s2, 0x18($sp)
.L8013A39C:
/* D0A9C 8013A39C 3C048035 */  lui       $a0, %hi(D_8034F800)
/* D0AA0 8013A3A0 2484F800 */  addiu     $a0, $a0, %lo(D_8034F800)
/* D0AA4 8013A3A4 3C058015 */  lui       $a1, %hi(D_8014EE60)
/* D0AA8 8013A3A8 94A5EE60 */  lhu       $a1, %lo(D_8014EE60)($a1)
/* D0AAC 8013A3AC 26310001 */  addiu     $s1, $s1, 1
/* D0AB0 8013A3B0 0C00A41B */  jal       _heap_malloc
/* D0AB4 8013A3B4 00052900 */   sll      $a1, $a1, 4
/* D0AB8 8013A3B8 AE020000 */  sw        $v0, ($s0)
/* D0ABC 8013A3BC 2A220002 */  slti      $v0, $s1, 2
/* D0AC0 8013A3C0 1440FFF6 */  bnez      $v0, .L8013A39C
/* D0AC4 8013A3C4 26100004 */   addiu    $s0, $s0, 4
/* D0AC8 8013A3C8 3C048035 */  lui       $a0, %hi(D_8034F800)
/* D0ACC 8013A3CC 2484F800 */  addiu     $a0, $a0, %lo(D_8034F800)
/* D0AD0 8013A3D0 0C00A41B */  jal       _heap_malloc
/* D0AD4 8013A3D4 24052B98 */   addiu    $a1, $zero, 0x2b98
/* D0AD8 8013A3D8 3C038015 */  lui       $v1, %hi(D_80156954)
/* D0ADC 8013A3DC 24636954 */  addiu     $v1, $v1, %lo(D_80156954)
/* D0AE0 8013A3E0 AC620000 */  sw        $v0, ($v1)
/* D0AE4 8013A3E4 0000882D */  daddu     $s1, $zero, $zero
/* D0AE8 8013A3E8 0060902D */  daddu     $s2, $v1, $zero
/* D0AEC 8013A3EC 0220802D */  daddu     $s0, $s1, $zero
.L8013A3F0:
/* D0AF0 8013A3F0 8E440000 */  lw        $a0, ($s2)
/* D0AF4 8013A3F4 0C04EA7A */  jal       func_8013A9E8
/* D0AF8 8013A3F8 00902021 */   addu     $a0, $a0, $s0
/* D0AFC 8013A3FC 8E440000 */  lw        $a0, ($s2)
/* D0B00 8013A400 26310001 */  addiu     $s1, $s1, 1
/* D0B04 8013A404 0C04EA72 */  jal       func_8013A9C8
/* D0B08 8013A408 00902021 */   addu     $a0, $a0, $s0
/* D0B0C 8013A40C 2A22005A */  slti      $v0, $s1, 0x5a
/* D0B10 8013A410 1440FFF7 */  bnez      $v0, .L8013A3F0
/* D0B14 8013A414 2610007C */   addiu    $s0, $s0, 0x7c
/* D0B18 8013A418 0000882D */  daddu     $s1, $zero, $zero
/* D0B1C 8013A41C 3C078015 */  lui       $a3, %hi(D_80156958)
/* D0B20 8013A420 24E76958 */  addiu     $a3, $a3, %lo(D_80156958)
/* D0B24 8013A424 2406FFFF */  addiu     $a2, $zero, -1
/* D0B28 8013A428 3C058015 */  lui       $a1, %hi(D_80156970)
/* D0B2C 8013A42C 24A56970 */  addiu     $a1, $a1, %lo(D_80156970)
/* D0B30 8013A430 3C048015 */  lui       $a0, %hi(D_80156968)
/* D0B34 8013A434 24846968 */  addiu     $a0, $a0, %lo(D_80156968)
/* D0B38 8013A438 3C038015 */  lui       $v1, %hi(D_80156960)
/* D0B3C 8013A43C 24636960 */  addiu     $v1, $v1, %lo(D_80156960)
.L8013A440:
/* D0B40 8013A440 02271021 */  addu      $v0, $s1, $a3
/* D0B44 8013A444 A0460000 */  sb        $a2, ($v0)
/* D0B48 8013A448 AC600000 */  sw        $zero, ($v1)
/* D0B4C 8013A44C AC800000 */  sw        $zero, ($a0)
/* D0B50 8013A450 24840004 */  addiu     $a0, $a0, 4
/* D0B54 8013A454 24630004 */  addiu     $v1, $v1, 4
/* D0B58 8013A458 26310001 */  addiu     $s1, $s1, 1
/* D0B5C 8013A45C 2A220002 */  slti      $v0, $s1, 2
/* D0B60 8013A460 1440FFF7 */  bnez      $v0, .L8013A440
/* D0B64 8013A464 A0A00000 */   sb       $zero, ($a1)
/* D0B68 8013A468 0000882D */  daddu     $s1, $zero, $zero
/* D0B6C 8013A46C 3C038015 */  lui       $v1, %hi(D_80156F20)
/* D0B70 8013A470 24636F20 */  addiu     $v1, $v1, %lo(D_80156F20)
.L8013A474:
/* D0B74 8013A474 AC600000 */  sw        $zero, ($v1)
/* D0B78 8013A478 A0600004 */  sb        $zero, 4($v1)
/* D0B7C 8013A47C A0600005 */  sb        $zero, 5($v1)
/* D0B80 8013A480 26310001 */  addiu     $s1, $s1, 1
/* D0B84 8013A484 2A220008 */  slti      $v0, $s1, 8
/* D0B88 8013A488 1440FFFA */  bnez      $v0, .L8013A474
/* D0B8C 8013A48C 24630008 */   addiu    $v1, $v1, 8
/* D0B90 8013A490 3C028007 */  lui       $v0, %hi(gCurrentDisplayContextIndex)
/* D0B94 8013A494 8C4241F4 */  lw        $v0, %lo(gCurrentDisplayContextIndex)($v0)
/* D0B98 8013A498 8FBF001C */  lw        $ra, 0x1c($sp)
/* D0B9C 8013A49C 8FB20018 */  lw        $s2, 0x18($sp)
/* D0BA0 8013A4A0 8FB10014 */  lw        $s1, 0x14($sp)
/* D0BA4 8013A4A4 8FB00010 */  lw        $s0, 0x10($sp)
/* D0BA8 8013A4A8 00021080 */  sll       $v0, $v0, 2
/* D0BAC 8013A4AC 3C018015 */  lui       $at, %hi(D_80156948)
/* D0BB0 8013A4B0 00220821 */  addu      $at, $at, $v0
/* D0BB4 8013A4B4 8C226948 */  lw        $v0, %lo(D_80156948)($at)
/* D0BB8 8013A4B8 3C018015 */  lui       $at, %hi(D_8014EE14)
/* D0BBC 8013A4BC A420EE14 */  sh        $zero, %lo(D_8014EE14)($at)
/* D0BC0 8013A4C0 3C018015 */  lui       $at, %hi(D_80156950)
/* D0BC4 8013A4C4 AC226950 */  sw        $v0, %lo(D_80156950)($at)
/* D0BC8 8013A4C8 03E00008 */  jr        $ra
/* D0BCC 8013A4CC 27BD0020 */   addiu    $sp, $sp, 0x20
