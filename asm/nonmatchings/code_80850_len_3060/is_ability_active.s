.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel is_ability_active
/* 831F8 800E9D48 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 831FC 800E9D4C AFBF0028 */  sw        $ra, 0x28($sp)
/* 83200 800E9D50 0080482D */  daddu     $t1, $a0, $zero
/* 83204 800E9D54 3C088011 */  lui       $t0, %hi(gPlayerData)
/* 83208 800E9D58 2508F290 */  addiu     $t0, $t0, %lo(gPlayerData)
/* 8320C 800E9D5C 0000282D */  daddu     $a1, $zero, $zero
/* 83210 800E9D60 00A0202D */  daddu     $a0, $a1, $zero
/* 83214 800E9D64 24070005 */  addiu     $a3, $zero, 5
/* 83218 800E9D68 27A20024 */  addiu     $v0, $sp, 0x24
.L800E9D6C:
/* 8321C 800E9D6C AC400000 */  sw        $zero, ($v0)
/* 83220 800E9D70 24E7FFFF */  addiu     $a3, $a3, -1
/* 83224 800E9D74 04E1FFFD */  bgez      $a3, .L800E9D6C
/* 83228 800E9D78 2442FFFC */   addiu    $v0, $v0, -4
/* 8322C 800E9D7C 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 83230 800E9D80 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 83234 800E9D84 9042007E */  lbu       $v0, 0x7e($v0)
/* 83238 800E9D88 30420001 */  andi      $v0, $v0, 1
/* 8323C 800E9D8C 144000C7 */  bnez      $v0, .L800EA0AC
/* 83240 800E9D90 0000102D */   daddu    $v0, $zero, $zero
/* 83244 800E9D94 0000382D */  daddu     $a3, $zero, $zero
/* 83248 800E9D98 3C038011 */  lui       $v1, 0x8011
/* 8324C 800E9D9C 2463BF60 */  addiu     $v1, $v1, -0x40a0
/* 83250 800E9DA0 00091080 */  sll       $v0, $t1, 2
/* 83254 800E9DA4 00435021 */  addu      $t2, $v0, $v1
/* 83258 800E9DA8 27A30010 */  addiu     $v1, $sp, 0x10
/* 8325C 800E9DAC 00041080 */  sll       $v0, $a0, 2
/* 83260 800E9DB0 00433021 */  addu      $a2, $v0, $v1
/* 83264 800E9DB4 00071040 */  sll       $v0, $a3, 1
.L800E9DB8:
/* 83268 800E9DB8 01021021 */  addu      $v0, $t0, $v0
/* 8326C 800E9DBC 84430208 */  lh        $v1, 0x208($v0)
/* 83270 800E9DC0 10600004 */  beqz      $v1, .L800E9DD4
/* 83274 800E9DC4 00031140 */   sll      $v0, $v1, 5
/* 83278 800E9DC8 3C038008 */  lui       $v1, %hi(gItemTable+0x1A)
/* 8327C 800E9DCC 00621821 */  addu      $v1, $v1, $v0
/* 83280 800E9DD0 906378FA */  lbu       $v1, %lo(gItemTable+0x1A)($v1)
.L800E9DD4:
/* 83284 800E9DD4 2D220038 */  sltiu     $v0, $t1, 0x38
/* 83288 800E9DD8 504000A9 */  beql      $v0, $zero, .L800EA080
/* 8328C 800E9DDC 24E70001 */   addiu    $a3, $a3, 1
/* 83290 800E9DE0 8D420000 */  lw        $v0, ($t2)
/* 83294 800E9DE4 00400008 */  jr        $v0
/* 83298 800E9DE8 00000000 */   nop      
/* 8329C 800E9DEC 0803A81D */  j         .L800EA074
/* 832A0 800E9DF0 2402004C */   addiu    $v0, $zero, 0x4c
/* 832A4 800E9DF4 0803A81D */  j         .L800EA074
/* 832A8 800E9DF8 24020040 */   addiu    $v0, $zero, 0x40
/* 832AC 800E9DFC 0803A81D */  j         .L800EA074
/* 832B0 800E9E00 2402004D */   addiu    $v0, $zero, 0x4d
/* 832B4 800E9E04 0803A81D */  j         .L800EA074
/* 832B8 800E9E08 24020052 */   addiu    $v0, $zero, 0x52
/* 832BC 800E9E0C 0803A81D */  j         .L800EA074
/* 832C0 800E9E10 24020035 */   addiu    $v0, $zero, 0x35
/* 832C4 800E9E14 24020053 */  addiu     $v0, $zero, 0x53
/* 832C8 800E9E18 50620001 */  beql      $v1, $v0, .L800E9E20
/* 832CC 800E9E1C 24A50001 */   addiu    $a1, $a1, 1
.L800E9E20:
/* 832D0 800E9E20 8102000A */  lb        $v0, 0xa($t0)
/* 832D4 800E9E24 50400096 */  beql      $v0, $zero, .L800EA080
/* 832D8 800E9E28 24E70001 */   addiu    $a3, $a3, 1
/* 832DC 800E9E2C 0803A81F */  j         .L800EA07C
/* 832E0 800E9E30 24A50001 */   addiu    $a1, $a1, 1
/* 832E4 800E9E34 0803A81D */  j         .L800EA074
/* 832E8 800E9E38 24020041 */   addiu    $v0, $zero, 0x41
/* 832EC 800E9E3C 0803A81D */  j         .L800EA074
/* 832F0 800E9E40 24020042 */   addiu    $v0, $zero, 0x42
/* 832F4 800E9E44 0803A81D */  j         .L800EA074
/* 832F8 800E9E48 2402005A */   addiu    $v0, $zero, 0x5a
/* 832FC 800E9E4C 0803A81D */  j         .L800EA074
/* 83300 800E9E50 2402003C */   addiu    $v0, $zero, 0x3c
/* 83304 800E9E54 0803A81D */  j         .L800EA074
/* 83308 800E9E58 2402004E */   addiu    $v0, $zero, 0x4e
/* 8330C 800E9E5C 0803A81D */  j         .L800EA074
/* 83310 800E9E60 2402005B */   addiu    $v0, $zero, 0x5b
/* 83314 800E9E64 0803A81D */  j         .L800EA074
/* 83318 800E9E68 2402003D */   addiu    $v0, $zero, 0x3d
/* 8331C 800E9E6C 0803A81D */  j         .L800EA074
/* 83320 800E9E70 24020043 */   addiu    $v0, $zero, 0x43
/* 83324 800E9E74 24020054 */  addiu     $v0, $zero, 0x54
/* 83328 800E9E78 14620007 */  bne       $v1, $v0, .L800E9E98
/* 8332C 800E9E7C 24020055 */   addiu    $v0, $zero, 0x55
/* 83330 800E9E80 24020001 */  addiu     $v0, $zero, 1
/* 83334 800E9E84 ACC20000 */  sw        $v0, ($a2)
/* 83338 800E9E88 24C60004 */  addiu     $a2, $a2, 4
/* 8333C 800E9E8C 00822021 */  addu      $a0, $a0, $v0
/* 83340 800E9E90 2405FFFF */  addiu     $a1, $zero, -1
/* 83344 800E9E94 24020055 */  addiu     $v0, $zero, 0x55
.L800E9E98:
/* 83348 800E9E98 14620007 */  bne       $v1, $v0, .L800E9EB8
/* 8334C 800E9E9C 24020056 */   addiu    $v0, $zero, 0x56
/* 83350 800E9EA0 24020002 */  addiu     $v0, $zero, 2
/* 83354 800E9EA4 ACC20000 */  sw        $v0, ($a2)
/* 83358 800E9EA8 24C60004 */  addiu     $a2, $a2, 4
/* 8335C 800E9EAC 24840001 */  addiu     $a0, $a0, 1
/* 83360 800E9EB0 2405FFFF */  addiu     $a1, $zero, -1
/* 83364 800E9EB4 24020056 */  addiu     $v0, $zero, 0x56
.L800E9EB8:
/* 83368 800E9EB8 14620007 */  bne       $v1, $v0, .L800E9ED8
/* 8336C 800E9EBC 24020057 */   addiu    $v0, $zero, 0x57
/* 83370 800E9EC0 24020003 */  addiu     $v0, $zero, 3
/* 83374 800E9EC4 ACC20000 */  sw        $v0, ($a2)
/* 83378 800E9EC8 24C60004 */  addiu     $a2, $a2, 4
/* 8337C 800E9ECC 24840001 */  addiu     $a0, $a0, 1
/* 83380 800E9ED0 2405FFFF */  addiu     $a1, $zero, -1
/* 83384 800E9ED4 24020057 */  addiu     $v0, $zero, 0x57
.L800E9ED8:
/* 83388 800E9ED8 14620007 */  bne       $v1, $v0, .L800E9EF8
/* 8338C 800E9EDC 24020058 */   addiu    $v0, $zero, 0x58
/* 83390 800E9EE0 24020004 */  addiu     $v0, $zero, 4
/* 83394 800E9EE4 ACC20000 */  sw        $v0, ($a2)
/* 83398 800E9EE8 00C23021 */  addu      $a2, $a2, $v0
/* 8339C 800E9EEC 24840001 */  addiu     $a0, $a0, 1
/* 833A0 800E9EF0 2405FFFF */  addiu     $a1, $zero, -1
/* 833A4 800E9EF4 24020058 */  addiu     $v0, $zero, 0x58
.L800E9EF8:
/* 833A8 800E9EF8 14620007 */  bne       $v1, $v0, .L800E9F18
/* 833AC 800E9EFC 24020059 */   addiu    $v0, $zero, 0x59
/* 833B0 800E9F00 24020005 */  addiu     $v0, $zero, 5
/* 833B4 800E9F04 ACC20000 */  sw        $v0, ($a2)
/* 833B8 800E9F08 24C60004 */  addiu     $a2, $a2, 4
/* 833BC 800E9F0C 24840001 */  addiu     $a0, $a0, 1
/* 833C0 800E9F10 2405FFFF */  addiu     $a1, $zero, -1
/* 833C4 800E9F14 24020059 */  addiu     $v0, $zero, 0x59
.L800E9F18:
/* 833C8 800E9F18 54620059 */  bnel      $v1, $v0, .L800EA080
/* 833CC 800E9F1C 24E70001 */   addiu    $a3, $a3, 1
/* 833D0 800E9F20 24020006 */  addiu     $v0, $zero, 6
/* 833D4 800E9F24 ACC20000 */  sw        $v0, ($a2)
/* 833D8 800E9F28 24C60004 */  addiu     $a2, $a2, 4
/* 833DC 800E9F2C 24840001 */  addiu     $a0, $a0, 1
/* 833E0 800E9F30 0803A81F */  j         .L800EA07C
/* 833E4 800E9F34 2405FFFF */   addiu    $a1, $zero, -1
/* 833E8 800E9F38 0803A81D */  j         .L800EA074
/* 833EC 800E9F3C 2402005C */   addiu    $v0, $zero, 0x5c
/* 833F0 800E9F40 0803A81D */  j         .L800EA074
/* 833F4 800E9F44 2402005D */   addiu    $v0, $zero, 0x5d
/* 833F8 800E9F48 0803A81D */  j         .L800EA074
/* 833FC 800E9F4C 2402005E */   addiu    $v0, $zero, 0x5e
/* 83400 800E9F50 0803A81D */  j         .L800EA074
/* 83404 800E9F54 24020044 */   addiu    $v0, $zero, 0x44
/* 83408 800E9F58 0803A81D */  j         .L800EA074
/* 8340C 800E9F5C 2402005F */   addiu    $v0, $zero, 0x5f
/* 83410 800E9F60 0803A81D */  j         .L800EA074
/* 83414 800E9F64 24020060 */   addiu    $v0, $zero, 0x60
/* 83418 800E9F68 0803A81D */  j         .L800EA074
/* 8341C 800E9F6C 2402004F */   addiu    $v0, $zero, 0x4f
/* 83420 800E9F70 0803A81D */  j         .L800EA074
/* 83424 800E9F74 24020061 */   addiu    $v0, $zero, 0x61
/* 83428 800E9F78 0803A81D */  j         .L800EA074
/* 8342C 800E9F7C 24020062 */   addiu    $v0, $zero, 0x62
/* 83430 800E9F80 0803A81D */  j         .L800EA074
/* 83434 800E9F84 24020063 */   addiu    $v0, $zero, 0x63
/* 83438 800E9F88 0803A81D */  j         .L800EA074
/* 8343C 800E9F8C 24020045 */   addiu    $v0, $zero, 0x45
/* 83440 800E9F90 0803A81D */  j         .L800EA074
/* 83444 800E9F94 2402003B */   addiu    $v0, $zero, 0x3b
/* 83448 800E9F98 0803A81D */  j         .L800EA074
/* 8344C 800E9F9C 2402006E */   addiu    $v0, $zero, 0x6e
/* 83450 800E9FA0 0803A81D */  j         .L800EA074
/* 83454 800E9FA4 24020064 */   addiu    $v0, $zero, 0x64
/* 83458 800E9FA8 0803A81D */  j         .L800EA074
/* 8345C 800E9FAC 24020065 */   addiu    $v0, $zero, 0x65
/* 83460 800E9FB0 0803A81D */  j         .L800EA074
/* 83464 800E9FB4 24020046 */   addiu    $v0, $zero, 0x46
/* 83468 800E9FB8 0803A81D */  j         .L800EA074
/* 8346C 800E9FBC 24020047 */   addiu    $v0, $zero, 0x47
/* 83470 800E9FC0 0803A81D */  j         .L800EA074
/* 83474 800E9FC4 2402003E */   addiu    $v0, $zero, 0x3e
/* 83478 800E9FC8 0803A81D */  j         .L800EA074
/* 8347C 800E9FCC 24020048 */   addiu    $v0, $zero, 0x48
/* 83480 800E9FD0 0803A81D */  j         .L800EA074
/* 83484 800E9FD4 24020066 */   addiu    $v0, $zero, 0x66
/* 83488 800E9FD8 0803A81D */  j         .L800EA074
/* 8348C 800E9FDC 24020049 */   addiu    $v0, $zero, 0x49
/* 83490 800E9FE0 0803A81D */  j         .L800EA074
/* 83494 800E9FE4 24020067 */   addiu    $v0, $zero, 0x67
/* 83498 800E9FE8 0803A81D */  j         .L800EA074
/* 8349C 800E9FEC 2402006D */   addiu    $v0, $zero, 0x6d
/* 834A0 800E9FF0 0803A81D */  j         .L800EA074
/* 834A4 800E9FF4 2402006A */   addiu    $v0, $zero, 0x6a
/* 834A8 800E9FF8 0803A81D */  j         .L800EA074
/* 834AC 800E9FFC 2402006C */   addiu    $v0, $zero, 0x6c
/* 834B0 800EA000 0803A81D */  j         .L800EA074
/* 834B4 800EA004 24020050 */   addiu    $v0, $zero, 0x50
/* 834B8 800EA008 0803A81D */  j         .L800EA074
/* 834BC 800EA00C 24020038 */   addiu    $v0, $zero, 0x38
/* 834C0 800EA010 0803A81D */  j         .L800EA074
/* 834C4 800EA014 24020068 */   addiu    $v0, $zero, 0x68
/* 834C8 800EA018 0803A81D */  j         .L800EA074
/* 834CC 800EA01C 24020069 */   addiu    $v0, $zero, 0x69
/* 834D0 800EA020 0803A81D */  j         .L800EA074
/* 834D4 800EA024 2402006B */   addiu    $v0, $zero, 0x6b
/* 834D8 800EA028 0803A81D */  j         .L800EA074
/* 834DC 800EA02C 2402006F */   addiu    $v0, $zero, 0x6f
/* 834E0 800EA030 0803A81D */  j         .L800EA074
/* 834E4 800EA034 24020070 */   addiu    $v0, $zero, 0x70
/* 834E8 800EA038 0803A81D */  j         .L800EA074
/* 834EC 800EA03C 24020071 */   addiu    $v0, $zero, 0x71
/* 834F0 800EA040 0803A81D */  j         .L800EA074
/* 834F4 800EA044 24020072 */   addiu    $v0, $zero, 0x72
/* 834F8 800EA048 0803A81D */  j         .L800EA074
/* 834FC 800EA04C 24020073 */   addiu    $v0, $zero, 0x73
/* 83500 800EA050 0803A81D */  j         .L800EA074
/* 83504 800EA054 24020033 */   addiu    $v0, $zero, 0x33
/* 83508 800EA058 0803A81D */  j         .L800EA074
/* 8350C 800EA05C 24020074 */   addiu    $v0, $zero, 0x74
/* 83510 800EA060 0803A81D */  j         .L800EA074
/* 83514 800EA064 24020075 */   addiu    $v0, $zero, 0x75
/* 83518 800EA068 0803A81D */  j         .L800EA074
/* 8351C 800EA06C 24020076 */   addiu    $v0, $zero, 0x76
/* 83520 800EA070 2402004A */  addiu     $v0, $zero, 0x4a
.L800EA074:
/* 83524 800EA074 50620001 */  beql      $v1, $v0, .L800EA07C
/* 83528 800EA078 24A50001 */   addiu    $a1, $a1, 1
.L800EA07C:
/* 8352C 800EA07C 24E70001 */  addiu     $a3, $a3, 1
.L800EA080:
/* 83530 800EA080 28E20040 */  slti      $v0, $a3, 0x40
/* 83534 800EA084 1440FF4C */  bnez      $v0, .L800E9DB8
/* 83538 800EA088 00071040 */   sll      $v0, $a3, 1
/* 8353C 800EA08C 04A10007 */  bgez      $a1, .L800EA0AC
/* 83540 800EA090 00A0102D */   daddu    $v0, $a1, $zero
/* 83544 800EA094 0C00A67F */  jal       rand_int
/* 83548 800EA098 2484FFFF */   addiu    $a0, $a0, -1
/* 8354C 800EA09C 00021080 */  sll       $v0, $v0, 2
/* 83550 800EA0A0 03A21021 */  addu      $v0, $sp, $v0
/* 83554 800EA0A4 8C450010 */  lw        $a1, 0x10($v0)
/* 83558 800EA0A8 00A0102D */  daddu     $v0, $a1, $zero
.L800EA0AC:
/* 8355C 800EA0AC 8FBF0028 */  lw        $ra, 0x28($sp)
/* 83560 800EA0B0 03E00008 */  jr        $ra
/* 83564 800EA0B4 27BD0030 */   addiu    $sp, $sp, 0x30
