.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel partner_flying_enable
/* 867C0 800ED310 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 867C4 800ED314 AFB00010 */  sw        $s0, 0x10($sp)
/* 867C8 800ED318 0080802D */  daddu     $s0, $a0, $zero
/* 867CC 800ED31C 3C048011 */  lui       $a0, %hi(D_8010CD38)
/* 867D0 800ED320 2484CD38 */  addiu     $a0, $a0, %lo(D_8010CD38)
/* 867D4 800ED324 0000302D */  daddu     $a2, $zero, $zero
/* 867D8 800ED328 3C028010 */  lui       $v0, %hi(D_800F833C)
/* 867DC 800ED32C 2442833C */  addiu     $v0, $v0, %lo(D_800F833C)
/* 867E0 800ED330 0040482D */  daddu     $t1, $v0, $zero
/* 867E4 800ED334 3C028010 */  lui       $v0, %hi(D_800F8340)
/* 867E8 800ED338 24428340 */  addiu     $v0, $v0, %lo(D_800F8340)
/* 867EC 800ED33C 0040402D */  daddu     $t0, $v0, $zero
/* 867F0 800ED340 3C028010 */  lui       $v0, %hi(D_800F8344)
/* 867F4 800ED344 24428344 */  addiu     $v0, $v0, %lo(D_800F8344)
/* 867F8 800ED348 0040382D */  daddu     $a3, $v0, $zero
/* 867FC 800ED34C AFBF0014 */  sw        $ra, 0x14($sp)
/* 86800 800ED350 C5200000 */  lwc1      $f0, ($t1)
/* 86804 800ED354 C5020000 */  lwc1      $f2, ($t0)
/* 86808 800ED358 C4E40000 */  lwc1      $f4, ($a3)
/* 8680C 800ED35C 2483000C */  addiu     $v1, $a0, 0xc
/* 86810 800ED360 E6000038 */  swc1      $f0, 0x38($s0)
/* 86814 800ED364 E602003C */  swc1      $f2, 0x3c($s0)
/* 86818 800ED368 E6040040 */  swc1      $f4, 0x40($s0)
.L800ED36C:
/* 8681C 800ED36C 24C60001 */  addiu     $a2, $a2, 1
/* 86820 800ED370 C5200000 */  lwc1      $f0, ($t1)
/* 86824 800ED374 C5020000 */  lwc1      $f2, ($t0)
/* 86828 800ED378 C4E40000 */  lwc1      $f4, ($a3)
/* 8682C 800ED37C 28C20028 */  slti      $v0, $a2, 0x28
/* 86830 800ED380 E460FFF8 */  swc1      $f0, -8($v1)
/* 86834 800ED384 E462FFFC */  swc1      $f2, -4($v1)
/* 86838 800ED388 E4640000 */  swc1      $f4, ($v1)
/* 8683C 800ED38C 24630010 */  addiu     $v1, $v1, 0x10
/* 86840 800ED390 A0800000 */  sb        $zero, ($a0)
/* 86844 800ED394 1440FFF5 */  bnez      $v0, .L800ED36C
/* 86848 800ED398 24840010 */   addiu    $a0, $a0, 0x10
/* 8684C 800ED39C 3C018011 */  lui       $at, %hi(D_8010CFB8)
/* 86850 800ED3A0 AC20CFB8 */  sw        $zero, %lo(D_8010CFB8)($at)
/* 86854 800ED3A4 3C018011 */  lui       $at, %hi(D_8010CFBC)
/* 86858 800ED3A8 AC20CFBC */  sw        $zero, %lo(D_8010CFBC)($at)
/* 8685C 800ED3AC 14A00005 */  bnez      $a1, .L800ED3C4
/* 86860 800ED3B0 00000000 */   nop
/* 86864 800ED3B4 3C018011 */  lui       $at, %hi(D_8010CFC8)
/* 86868 800ED3B8 A420CFC8 */  sh        $zero, %lo(D_8010CFC8)($at)
/* 8686C 800ED3BC 0803B50B */  j         .L800ED42C
/* 86870 800ED3C0 00000000 */   nop
.L800ED3C4:
/* 86874 800ED3C4 3C048011 */  lui       $a0, %hi(D_8010CFC4)
/* 86878 800ED3C8 2484CFC4 */  addiu     $a0, $a0, %lo(D_8010CFC4)
/* 8687C 800ED3CC 8C830000 */  lw        $v1, ($a0)
/* 86880 800ED3D0 14600009 */  bnez      $v1, .L800ED3F8
/* 86884 800ED3D4 24020001 */   addiu    $v0, $zero, 1
/* 86888 800ED3D8 2402000F */  addiu     $v0, $zero, 0xf
/* 8688C 800ED3DC 3C018011 */  lui       $at, %hi(D_8010CFC8)
/* 86890 800ED3E0 A422CFC8 */  sh        $v0, %lo(D_8010CFC8)($at)
/* 86894 800ED3E4 24020002 */  addiu     $v0, $zero, 2
/* 86898 800ED3E8 3C018011 */  lui       $at, %hi(D_8010CFCA)
/* 8689C 800ED3EC A422CFCA */  sh        $v0, %lo(D_8010CFCA)($at)
/* 868A0 800ED3F0 0803B50D */  j         .L800ED434
/* 868A4 800ED3F4 00000000 */   nop
.L800ED3F8:
/* 868A8 800ED3F8 10620003 */  beq       $v1, $v0, .L800ED408
/* 868AC 800ED3FC 24020003 */   addiu    $v0, $zero, 3
/* 868B0 800ED400 14620006 */  bne       $v1, $v0, .L800ED41C
/* 868B4 800ED404 24020002 */   addiu    $v0, $zero, 2
.L800ED408:
/* 868B8 800ED408 AC800000 */  sw        $zero, ($a0)
/* 868BC 800ED40C 3C018011 */  lui       $at, %hi(D_8010CFC8)
/* 868C0 800ED410 A420CFC8 */  sh        $zero, %lo(D_8010CFC8)($at)
/* 868C4 800ED414 0803B50B */  j         .L800ED42C
/* 868C8 800ED418 00000000 */   nop
.L800ED41C:
/* 868CC 800ED41C 14620005 */  bne       $v1, $v0, .L800ED434
/* 868D0 800ED420 24020032 */   addiu    $v0, $zero, 0x32
/* 868D4 800ED424 3C018011 */  lui       $at, %hi(D_8010CFC8)
/* 868D8 800ED428 A422CFC8 */  sh        $v0, %lo(D_8010CFC8)($at)
.L800ED42C:
/* 868DC 800ED42C 3C018011 */  lui       $at, %hi(D_8010CFCA)
/* 868E0 800ED430 A420CFCA */  sh        $zero, %lo(D_8010CFCA)($at)
.L800ED434:
/* 868E4 800ED434 3C038011 */  lui       $v1, %hi(D_8010CFD8)
/* 868E8 800ED438 8C63CFD8 */  lw        $v1, %lo(D_8010CFD8)($v1)
/* 868EC 800ED43C 3C014220 */  lui       $at, 0x4220
/* 868F0 800ED440 44810000 */  mtc1      $at, $f0
/* 868F4 800ED444 0200202D */  daddu     $a0, $s0, $zero
/* 868F8 800ED448 3C018011 */  lui       $at, %hi(D_8010CFCE)
/* 868FC 800ED44C A420CFCE */  sh        $zero, %lo(D_8010CFCE)($at)
/* 86900 800ED450 3C018011 */  lui       $at, %hi(D_8010CFCC)
/* 86904 800ED454 A420CFCC */  sh        $zero, %lo(D_8010CFCC)($at)
/* 86908 800ED458 000310C0 */  sll       $v0, $v1, 3
/* 8690C 800ED45C 00431021 */  addu      $v0, $v0, $v1
/* 86910 800ED460 00021080 */  sll       $v0, $v0, 2
/* 86914 800ED464 3C038010 */  lui       $v1, %hi(gPartnerAnimations+0x14)
/* 86918 800ED468 00621821 */  addu      $v1, $v1, $v0
/* 8691C 800ED46C 8C63835C */  lw        $v1, %lo(gPartnerAnimations+0x14)($v1)
/* 86920 800ED470 24020010 */  addiu     $v0, $zero, 0x10
/* 86924 800ED474 3C018010 */  lui       $at, %hi(D_800F802C)
/* 86928 800ED478 AC22802C */  sw        $v0, %lo(D_800F802C)($at)
/* 8692C 800ED47C 3C018011 */  lui       $at, %hi(D_8010CFC0)
/* 86930 800ED480 E420CFC0 */  swc1      $f0, %lo(D_8010CFC0)($at)
/* 86934 800ED484 0C03A96E */  jal       func_800EA5B8
/* 86938 800ED488 AE030028 */   sw       $v1, 0x28($s0)
/* 8693C 800ED48C 8E020000 */  lw        $v0, ($s0)
/* 86940 800ED490 3C030001 */  lui       $v1, 1
/* 86944 800ED494 AE030080 */  sw        $v1, 0x80($s0)
/* 86948 800ED498 2403FDFF */  addiu     $v1, $zero, -0x201
/* 8694C 800ED49C 34420100 */  ori       $v0, $v0, 0x100
/* 86950 800ED4A0 00431024 */  and       $v0, $v0, $v1
/* 86954 800ED4A4 AE020000 */  sw        $v0, ($s0)
/* 86958 800ED4A8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 8695C 800ED4AC 8FB00010 */  lw        $s0, 0x10($sp)
/* 86960 800ED4B0 03E00008 */  jr        $ra
/* 86964 800ED4B4 27BD0018 */   addiu    $sp, $sp, 0x18
