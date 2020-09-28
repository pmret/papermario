.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005DECC
/* 392CC 8005DECC 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 392D0 8005DED0 AFB10014 */  sw        $s1, 0x14($sp)
/* 392D4 8005DED4 0080882D */  daddu     $s1, $a0, $zero
/* 392D8 8005DED8 AFB20018 */  sw        $s2, 0x18($sp)
/* 392DC 8005DEDC 00A0902D */  daddu     $s2, $a1, $zero
/* 392E0 8005DEE0 AFB3001C */  sw        $s3, 0x1c($sp)
/* 392E4 8005DEE4 00C0982D */  daddu     $s3, $a2, $zero
/* 392E8 8005DEE8 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 392EC 8005DEEC 4487A000 */  mtc1      $a3, $f20
/* 392F0 8005DEF0 240402A4 */  addiu     $a0, $zero, 0x2a4
/* 392F4 8005DEF4 AFBF0020 */  sw        $ra, 0x20($sp)
/* 392F8 8005DEF8 0C00AB39 */  jal       heap_malloc
/* 392FC 8005DEFC AFB00010 */   sw       $s0, 0x10($sp)
/* 39300 8005DF00 0040202D */  daddu     $a0, $v0, $zero
/* 39304 8005DF04 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* 39308 8005DF08 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* 3930C 8005DF0C 14800003 */  bnez      $a0, .L8005DF1C
/* 39310 8005DF10 AE240020 */   sw       $a0, 0x20($s1)
.L8005DF14:
/* 39314 8005DF14 080177C5 */  j         .L8005DF14
/* 39318 8005DF18 00000000 */   nop      
.L8005DF1C:
/* 3931C 8005DF1C 0000282D */  daddu     $a1, $zero, $zero
/* 39320 8005DF20 0080182D */  daddu     $v1, $a0, $zero
.L8005DF24:
/* 39324 8005DF24 C6000028 */  lwc1      $f0, 0x28($s0)
/* 39328 8005DF28 E4600004 */  swc1      $f0, 4($v1)
/* 3932C 8005DF2C C600002C */  lwc1      $f0, 0x2c($s0)
/* 39330 8005DF30 24A50001 */  addiu     $a1, $a1, 1
/* 39334 8005DF34 E4600008 */  swc1      $f0, 8($v1)
/* 39338 8005DF38 C6000030 */  lwc1      $f0, 0x30($s0)
/* 3933C 8005DF3C 28A20028 */  slti      $v0, $a1, 0x28
/* 39340 8005DF40 A0600000 */  sb        $zero, ($v1)
/* 39344 8005DF44 E460000C */  swc1      $f0, 0xc($v1)
/* 39348 8005DF48 1440FFF6 */  bnez      $v0, .L8005DF24
/* 3934C 8005DF4C 24630010 */   addiu    $v1, $v1, 0x10
/* 39350 8005DF50 AC800280 */  sw        $zero, 0x280($a0)
/* 39354 8005DF54 AC800284 */  sw        $zero, 0x284($a0)
/* 39358 8005DF58 AC800288 */  sw        $zero, 0x288($a0)
/* 3935C 8005DF5C AC92028C */  sw        $s2, 0x28c($a0)
/* 39360 8005DF60 AC930290 */  sw        $s3, 0x290($a0)
/* 39364 8005DF64 E4940294 */  swc1      $f20, 0x294($a0)
/* 39368 8005DF68 C7A00040 */  lwc1      $f0, 0x40($sp)
/* 3936C 8005DF6C 0260102D */  daddu     $v0, $s3, $zero
/* 39370 8005DF70 E4800298 */  swc1      $f0, 0x298($a0)
/* 39374 8005DF74 C7A00044 */  lwc1      $f0, 0x44($sp)
/* 39378 8005DF78 46800020 */  cvt.s.w   $f0, $f0
/* 3937C 8005DF7C E480029C */  swc1      $f0, 0x29c($a0)
/* 39380 8005DF80 C7A00048 */  lwc1      $f0, 0x48($sp)
/* 39384 8005DF84 46800020 */  cvt.s.w   $f0, $f0
/* 39388 8005DF88 E48002A0 */  swc1      $f0, 0x2a0($a0)
/* 3938C 8005DF8C 8C440010 */  lw        $a0, 0x10($v0)
/* 39390 8005DF90 8E220000 */  lw        $v0, ($s1)
/* 39394 8005DF94 2403FEFF */  addiu     $v1, $zero, -0x101
/* 39398 8005DF98 AE20001C */  sw        $zero, 0x1c($s1)
/* 3939C 8005DF9C 34420200 */  ori       $v0, $v0, 0x200
/* 393A0 8005DFA0 00431024 */  and       $v0, $v0, $v1
/* 393A4 8005DFA4 AE220000 */  sw        $v0, ($s1)
/* 393A8 8005DFA8 3C020001 */  lui       $v0, 1
/* 393AC 8005DFAC AE220080 */  sw        $v0, 0x80($s1)
/* 393B0 8005DFB0 AE240028 */  sw        $a0, 0x28($s1)
/* 393B4 8005DFB4 8FBF0020 */  lw        $ra, 0x20($sp)
/* 393B8 8005DFB8 8FB3001C */  lw        $s3, 0x1c($sp)
/* 393BC 8005DFBC 8FB20018 */  lw        $s2, 0x18($sp)
/* 393C0 8005DFC0 8FB10014 */  lw        $s1, 0x14($sp)
/* 393C4 8005DFC4 8FB00010 */  lw        $s0, 0x10($sp)
/* 393C8 8005DFC8 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 393CC 8005DFCC 03E00008 */  jr        $ra
/* 393D0 8005DFD0 27BD0030 */   addiu    $sp, $sp, 0x30
