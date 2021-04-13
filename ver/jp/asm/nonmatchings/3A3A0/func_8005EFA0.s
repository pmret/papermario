.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005EFA0
/* 3A3A0 8005EFA0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 3A3A4 8005EFA4 AFB10014 */  sw        $s1, 0x14($sp)
/* 3A3A8 8005EFA8 00A0882D */  daddu     $s1, $a1, $zero
/* 3A3AC 8005EFAC AFBF0018 */  sw        $ra, 0x18($sp)
/* 3A3B0 8005EFB0 AFB00010 */  sw        $s0, 0x10($sp)
/* 3A3B4 8005EFB4 3C01800A */  lui       $at, %hi(D_8009A638)
/* 3A3B8 8005EFB8 AC24A638 */  sw        $a0, %lo(D_8009A638)($at)
/* 3A3BC 8005EFBC 3C018007 */  lui       $at, %hi(D_800773D0)
/* 3A3C0 8005EFC0 AC3173D0 */  sw        $s1, %lo(D_800773D0)($at)
/* 3A3C4 8005EFC4 3C01800A */  lui       $at, %hi(D_8009A5D0)
/* 3A3C8 8005EFC8 AC20A5D0 */  sw        $zero, %lo(D_8009A5D0)($at)
/* 3A3CC 8005EFCC 8C820000 */  lw        $v0, ($a0)
/* 3A3D0 8005EFD0 3C01800A */  lui       $at, %hi(D_8009A62C)
/* 3A3D4 8005EFD4 AC22A62C */  sw        $v0, %lo(D_8009A62C)($at)
/* 3A3D8 8005EFD8 0C018008 */  jal       func_80060020
/* 3A3DC 8005EFDC 24040001 */   addiu    $a0, $zero, 1
/* 3A3E0 8005EFE0 0C017B10 */  jal       func_8005EC40
/* 3A3E4 8005EFE4 322400FF */   andi     $a0, $s1, 0xff
/* 3A3E8 8005EFE8 2E220002 */  sltiu     $v0, $s1, 2
/* 3A3EC 8005EFEC 1440002A */  bnez      $v0, .L8005F098
/* 3A3F0 8005EFF0 2625FFFF */   addiu    $a1, $s1, -1
/* 3A3F4 8005EFF4 10A0000B */  beqz      $a1, .L8005F024
/* 3A3F8 8005EFF8 0000802D */   daddu    $s0, $zero, $zero
/* 3A3FC 8005EFFC 3C04800A */  lui       $a0, %hi(D_8009A638)
/* 3A400 8005F000 8C84A638 */  lw        $a0, %lo(D_8009A638)($a0)
.L8005F004:
/* 3A404 8005F004 8C830000 */  lw        $v1, ($a0)
/* 3A408 8005F008 8C820004 */  lw        $v0, 4($a0)
/* 3A40C 8005F00C 14620006 */  bne       $v1, $v0, .L8005F028
/* 3A410 8005F010 2622FFFF */   addiu    $v0, $s1, -1
/* 3A414 8005F014 26100001 */  addiu     $s0, $s0, 1
/* 3A418 8005F018 0205102B */  sltu      $v0, $s0, $a1
/* 3A41C 8005F01C 1440FFF9 */  bnez      $v0, .L8005F004
/* 3A420 8005F020 24840004 */   addiu    $a0, $a0, 4
.L8005F024:
/* 3A424 8005F024 2622FFFF */  addiu     $v0, $s1, -1
.L8005F028:
/* 3A428 8005F028 1602000C */  bne       $s0, $v0, .L8005F05C
/* 3A42C 8005F02C 00000000 */   nop
/* 3A430 8005F030 0C017B10 */  jal       func_8005EC40
/* 3A434 8005F034 24040001 */   addiu    $a0, $zero, 1
/* 3A438 8005F038 08017C26 */  j         .L8005F098
/* 3A43C 8005F03C 00000000 */   nop
.L8005F040:
/* 3A440 8005F040 8C820000 */  lw        $v0, ($a0)
/* 3A444 8005F044 3C01800A */  lui       $at, %hi(D_8009A5D0)
/* 3A448 8005F048 AC30A5D0 */  sw        $s0, %lo(D_8009A5D0)($at)
/* 3A44C 8005F04C 3C01800A */  lui       $at, %hi(D_8009A62C)
/* 3A450 8005F050 AC22A62C */  sw        $v0, %lo(D_8009A62C)($at)
/* 3A454 8005F054 08017C26 */  j         .L8005F098
/* 3A458 8005F058 00000000 */   nop
.L8005F05C:
/* 3A45C 8005F05C 1220000E */  beqz      $s1, .L8005F098
/* 3A460 8005F060 0000802D */   daddu    $s0, $zero, $zero
.L8005F064:
/* 3A464 8005F064 0C019A60 */  jal       func_80066980
/* 3A468 8005F068 00000000 */   nop
/* 3A46C 8005F06C 3C03800A */  lui       $v1, %hi(D_8009A638)
/* 3A470 8005F070 8C63A638 */  lw        $v1, %lo(D_8009A638)($v1)
/* 3A474 8005F074 00102080 */  sll       $a0, $s0, 2
/* 3A478 8005F078 00832021 */  addu      $a0, $a0, $v1
/* 3A47C 8005F07C 8C830000 */  lw        $v1, ($a0)
/* 3A480 8005F080 1443FFEF */  bne       $v0, $v1, .L8005F040
/* 3A484 8005F084 00000000 */   nop
/* 3A488 8005F088 26100001 */  addiu     $s0, $s0, 1
/* 3A48C 8005F08C 0211102B */  sltu      $v0, $s0, $s1
/* 3A490 8005F090 1440FFF4 */  bnez      $v0, .L8005F064
/* 3A494 8005F094 00000000 */   nop
.L8005F098:
/* 3A498 8005F098 8FBF0018 */  lw        $ra, 0x18($sp)
/* 3A49C 8005F09C 8FB10014 */  lw        $s1, 0x14($sp)
/* 3A4A0 8005F0A0 8FB00010 */  lw        $s0, 0x10($sp)
/* 3A4A4 8005F0A4 03E00008 */  jr        $ra
/* 3A4A8 8005F0A8 27BD0020 */   addiu    $sp, $sp, 0x20
/* 3A4AC 8005F0AC 00000000 */  nop
