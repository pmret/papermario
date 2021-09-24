.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_60_main
/* 37A3F0 E0078000 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 37A3F4 E0078004 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 37A3F8 E0078008 4485A000 */  mtc1      $a1, $f20
/* 37A3FC E007800C AFB20030 */  sw        $s2, 0x30($sp)
/* 37A400 E0078010 0080902D */  daddu     $s2, $a0, $zero
/* 37A404 E0078014 F7B60040 */  sdc1      $f22, 0x40($sp)
/* 37A408 E0078018 4486B000 */  mtc1      $a2, $f22
/* 37A40C E007801C 27A40010 */  addiu     $a0, $sp, 0x10
/* 37A410 E0078020 F7B80048 */  sdc1      $f24, 0x48($sp)
/* 37A414 E0078024 4487C000 */  mtc1      $a3, $f24
/* 37A418 E0078028 3C02E008 */  lui       $v0, %hi(func_E0078124)
/* 37A41C E007802C 24428124 */  addiu     $v0, $v0, %lo(func_E0078124)
/* 37A420 E0078030 AFA20018 */  sw        $v0, 0x18($sp)
/* 37A424 E0078034 3C02E008 */  lui       $v0, %hi(func_E007812C)
/* 37A428 E0078038 2442812C */  addiu     $v0, $v0, %lo(func_E007812C)
/* 37A42C E007803C AFA2001C */  sw        $v0, 0x1c($sp)
/* 37A430 E0078040 3C02E008 */  lui       $v0, %hi(func_E0078210)
/* 37A434 E0078044 24428210 */  addiu     $v0, $v0, %lo(func_E0078210)
/* 37A438 E0078048 AFA20020 */  sw        $v0, 0x20($sp)
/* 37A43C E007804C 2402003C */  addiu     $v0, $zero, 0x3c
/* 37A440 E0078050 AFBF0034 */  sw        $ra, 0x34($sp)
/* 37A444 E0078054 AFB1002C */  sw        $s1, 0x2c($sp)
/* 37A448 E0078058 AFB00028 */  sw        $s0, 0x28($sp)
/* 37A44C E007805C AFA00010 */  sw        $zero, 0x10($sp)
/* 37A450 E0078060 AFA00024 */  sw        $zero, 0x24($sp)
/* 37A454 E0078064 0C080124 */  jal       shim_create_effect_instance
/* 37A458 E0078068 AFA20014 */   sw       $v0, 0x14($sp)
/* 37A45C E007806C 24040024 */  addiu     $a0, $zero, 0x24
/* 37A460 E0078070 24030001 */  addiu     $v1, $zero, 1
/* 37A464 E0078074 0040882D */  daddu     $s1, $v0, $zero
/* 37A468 E0078078 0C08012C */  jal       shim_general_heap_malloc
/* 37A46C E007807C AE230008 */   sw       $v1, 8($s1)
/* 37A470 E0078080 0040802D */  daddu     $s0, $v0, $zero
/* 37A474 E0078084 16000003 */  bnez      $s0, .LE0078094
/* 37A478 E0078088 AE22000C */   sw       $v0, 0xc($s1)
.LE007808C:
/* 37A47C E007808C 0801E023 */  j         .LE007808C
/* 37A480 E0078090 00000000 */   nop
.LE0078094:
/* 37A484 E0078094 324200FF */  andi      $v0, $s2, 0xff
/* 37A488 E0078098 AE020000 */  sw        $v0, ($s0)
/* 37A48C E007809C 2A420100 */  slti      $v0, $s2, 0x100
/* 37A490 E00780A0 14400002 */  bnez      $v0, .LE00780AC
/* 37A494 E00780A4 24020064 */   addiu    $v0, $zero, 0x64
/* 37A498 E00780A8 24020050 */  addiu     $v0, $zero, 0x50
.LE00780AC:
/* 37A49C E00780AC AE020014 */  sw        $v0, 0x14($s0)
/* 37A4A0 E00780B0 3C04E008 */  lui       $a0, %hi(D_E00789A8)
/* 37A4A4 E00780B4 248489A8 */  addiu     $a0, $a0, %lo(D_E00789A8)
/* 37A4A8 E00780B8 AE000018 */  sw        $zero, 0x18($s0)
/* 37A4AC E00780BC 8C820000 */  lw        $v0, ($a0)
/* 37A4B0 E00780C0 2403007F */  addiu     $v1, $zero, 0x7f
/* 37A4B4 E00780C4 AE030010 */  sw        $v1, 0x10($s0)
/* 37A4B8 E00780C8 E6140004 */  swc1      $f20, 4($s0)
/* 37A4BC E00780CC E6160008 */  swc1      $f22, 8($s0)
/* 37A4C0 E00780D0 E618000C */  swc1      $f24, 0xc($s0)
/* 37A4C4 E00780D4 AE02001C */  sw        $v0, 0x1c($s0)
/* 37A4C8 E00780D8 24420001 */  addiu     $v0, $v0, 1
/* 37A4CC E00780DC AC820000 */  sw        $v0, ($a0)
/* 37A4D0 E00780E0 28420010 */  slti      $v0, $v0, 0x10
/* 37A4D4 E00780E4 50400001 */  beql      $v0, $zero, .LE00780EC
/* 37A4D8 E00780E8 AC800000 */   sw       $zero, ($a0)
.LE00780EC:
/* 37A4DC E00780EC 0C080138 */  jal       shim_rand_int
/* 37A4E0 E00780F0 24040007 */   addiu    $a0, $zero, 7
/* 37A4E4 E00780F4 AE020020 */  sw        $v0, 0x20($s0)
/* 37A4E8 E00780F8 8FA20064 */  lw        $v0, 0x64($sp)
/* 37A4EC E00780FC AC510000 */  sw        $s1, ($v0)
/* 37A4F0 E0078100 8FBF0034 */  lw        $ra, 0x34($sp)
/* 37A4F4 E0078104 8FB20030 */  lw        $s2, 0x30($sp)
/* 37A4F8 E0078108 8FB1002C */  lw        $s1, 0x2c($sp)
/* 37A4FC E007810C 8FB00028 */  lw        $s0, 0x28($sp)
/* 37A500 E0078110 D7B80048 */  ldc1      $f24, 0x48($sp)
/* 37A504 E0078114 D7B60040 */  ldc1      $f22, 0x40($sp)
/* 37A508 E0078118 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 37A50C E007811C 03E00008 */  jr        $ra
/* 37A510 E0078120 27BD0050 */   addiu    $sp, $sp, 0x50
