.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E004E214
/* 35BBE4 E004E214 27BDFF30 */  addiu     $sp, $sp, -0xd0
/* 35BBE8 E004E218 0080302D */  daddu     $a2, $a0, $zero
/* 35BBEC E004E21C 3C07DB06 */  lui       $a3, 0xdb06
/* 35BBF0 E004E220 34E70024 */  ori       $a3, $a3, 0x24
/* 35BBF4 E004E224 27A40020 */  addiu     $a0, $sp, 0x20
/* 35BBF8 E004E228 AFB700BC */  sw        $s7, 0xbc($sp)
/* 35BBFC E004E22C 3C17800A */  lui       $s7, 0x800a
/* 35BC00 E004E230 26F7A66C */  addiu     $s7, $s7, -0x5994
/* 35BC04 E004E234 AFB600B8 */  sw        $s6, 0xb8($sp)
/* 35BC08 E004E238 3C160001 */  lui       $s6, 1
/* 35BC0C E004E23C 36D61630 */  ori       $s6, $s6, 0x1630
/* 35BC10 E004E240 AFBF00C4 */  sw        $ra, 0xc4($sp)
/* 35BC14 E004E244 AFBE00C0 */  sw        $fp, 0xc0($sp)
/* 35BC18 E004E248 AFB500B4 */  sw        $s5, 0xb4($sp)
/* 35BC1C E004E24C AFB400B0 */  sw        $s4, 0xb0($sp)
/* 35BC20 E004E250 AFB300AC */  sw        $s3, 0xac($sp)
/* 35BC24 E004E254 AFB200A8 */  sw        $s2, 0xa8($sp)
/* 35BC28 E004E258 AFB100A4 */  sw        $s1, 0xa4($sp)
/* 35BC2C E004E25C AFB000A0 */  sw        $s0, 0xa0($sp)
/* 35BC30 E004E260 F7B400C8 */  sdc1      $f20, 0xc8($sp)
/* 35BC34 E004E264 8EE80000 */  lw        $t0, ($s7)
/* 35BC38 E004E268 8CD1000C */  lw        $s1, 0xc($a2)
/* 35BC3C E004E26C 4480A000 */  mtc1      $zero, $f20
/* 35BC40 E004E270 3C09E005 */  lui       $t1, 0xe005
/* 35BC44 E004E274 8D29E5EC */  lw        $t1, -0x1a14($t1)
/* 35BC48 E004E278 3C014380 */  lui       $at, 0x4380
/* 35BC4C E004E27C 44812000 */  mtc1      $at, $f4
/* 35BC50 E004E280 0100182D */  daddu     $v1, $t0, $zero
/* 35BC54 E004E284 25080008 */  addiu     $t0, $t0, 8
/* 35BC58 E004E288 96220000 */  lhu       $v0, ($s1)
/* 35BC5C E004E28C 4405A000 */  mfc1      $a1, $f20
/* 35BC60 E004E290 C6260020 */  lwc1      $f6, 0x20($s1)
/* 35BC64 E004E294 00021080 */  sll       $v0, $v0, 2
/* 35BC68 E004E298 3C1EE005 */  lui       $fp, 0xe005
/* 35BC6C E004E29C 03C2F021 */  addu      $fp, $fp, $v0
/* 35BC70 E004E2A0 8FDEE5E0 */  lw        $fp, -0x1a20($fp)
/* 35BC74 E004E2A4 3C02E700 */  lui       $v0, 0xe700
/* 35BC78 E004E2A8 4600328D */  trunc.w.s $f10, $f6
/* 35BC7C E004E2AC 44145000 */  mfc1      $s4, $f10
/* 35BC80 E004E2B0 00000000 */  nop       
/* 35BC84 E004E2B4 44941000 */  mtc1      $s4, $f2
/* 35BC88 E004E2B8 00000000 */  nop       
/* 35BC8C E004E2BC 468010A0 */  cvt.s.w   $f2, $f2
/* 35BC90 E004E2C0 3A950007 */  xori      $s5, $s4, 7
/* 35BC94 E004E2C4 2EB50001 */  sltiu     $s5, $s5, 1
/* 35BC98 E004E2C8 46023181 */  sub.s     $f6, $f6, $f2
/* 35BC9C E004E2CC AC620000 */  sw        $v0, ($v1)
/* 35BCA0 E004E2D0 AC600004 */  sw        $zero, 4($v1)
/* 35BCA4 E004E2D4 AD070000 */  sw        $a3, ($t0)
/* 35BCA8 E004E2D8 8CC20010 */  lw        $v0, 0x10($a2)
/* 35BCAC E004E2DC 4407A000 */  mfc1      $a3, $f20
/* 35BCB0 E004E2E0 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 35BCB4 E004E2E4 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 35BCB8 E004E2E8 8C46001C */  lw        $a2, 0x1c($v0)
/* 35BCBC E004E2EC 3C02DE00 */  lui       $v0, 0xde00
/* 35BCC0 E004E2F0 AD020008 */  sw        $v0, 8($t0)
/* 35BCC4 E004E2F4 3C028000 */  lui       $v0, 0x8000
/* 35BCC8 E004E2F8 AD09000C */  sw        $t1, 0xc($t0)
/* 35BCCC E004E2FC 00C23021 */  addu      $a2, $a2, $v0
/* 35BCD0 E004E300 00031080 */  sll       $v0, $v1, 2
/* 35BCD4 E004E304 00431021 */  addu      $v0, $v0, $v1
/* 35BCD8 E004E308 00021080 */  sll       $v0, $v0, 2
/* 35BCDC E004E30C 00431023 */  subu      $v0, $v0, $v1
/* 35BCE0 E004E310 000218C0 */  sll       $v1, $v0, 3
/* 35BCE4 E004E314 00431021 */  addu      $v0, $v0, $v1
/* 35BCE8 E004E318 000210C0 */  sll       $v0, $v0, 3
/* 35BCEC E004E31C AD060004 */  sw        $a2, 4($t0)
/* 35BCF0 E004E320 3C01800B */  lui       $at, 0x800b
/* 35BCF4 E004E324 00220821 */  addu      $at, $at, $v0
/* 35BCF8 E004E328 C4281DEC */  lwc1      $f8, 0x1dec($at)
/* 35BCFC E004E32C C6200010 */  lwc1      $f0, 0x10($s1)
/* 35BD00 E004E330 25020008 */  addiu     $v0, $t0, 8
/* 35BD04 E004E334 AEE80000 */  sw        $t0, ($s7)
/* 35BD08 E004E338 46004207 */  neg.s     $f8, $f8
/* 35BD0C E004E33C E7A00010 */  swc1      $f0, 0x10($sp)
/* 35BD10 E004E340 C6200004 */  lwc1      $f0, 4($s1)
/* 35BD14 E004E344 44064000 */  mfc1      $a2, $f8
/* 35BD18 E004E348 46043182 */  mul.s     $f6, $f6, $f4
/* 35BD1C E004E34C 00000000 */  nop       
/* 35BD20 E004E350 AEE20000 */  sw        $v0, ($s7)
/* 35BD24 E004E354 E7A00014 */  swc1      $f0, 0x14($sp)
/* 35BD28 E004E358 C6200008 */  lwc1      $f0, 8($s1)
/* 35BD2C E004E35C 25080010 */  addiu     $t0, $t0, 0x10
/* 35BD30 E004E360 AEE80000 */  sw        $t0, ($s7)
/* 35BD34 E004E364 E7A00018 */  swc1      $f0, 0x18($sp)
/* 35BD38 E004E368 C620000C */  lwc1      $f0, 0xc($s1)
/* 35BD3C E004E36C 4600328D */  trunc.w.s $f10, $f6
/* 35BD40 E004E370 44135000 */  mfc1      $s3, $f10
/* 35BD44 E004E374 0C080180 */  jal       func_E0200600
/* 35BD48 E004E378 E7A0001C */   swc1     $f0, 0x1c($sp)
/* 35BD4C E004E37C 27B00060 */  addiu     $s0, $sp, 0x60
/* 35BD50 E004E380 0200202D */  daddu     $a0, $s0, $zero
/* 35BD54 E004E384 3C0541A0 */  lui       $a1, 0x41a0
/* 35BD58 E004E388 4406A000 */  mfc1      $a2, $f20
/* 35BD5C E004E38C 3C013F80 */  lui       $at, 0x3f80
/* 35BD60 E004E390 44810000 */  mtc1      $at, $f0
/* 35BD64 E004E394 00C0382D */  daddu     $a3, $a2, $zero
/* 35BD68 E004E398 0C080104 */  jal       func_E0200410
/* 35BD6C E004E39C E7A00010 */   swc1     $f0, 0x10($sp)
/* 35BD70 E004E3A0 0200202D */  daddu     $a0, $s0, $zero
/* 35BD74 E004E3A4 27A50020 */  addiu     $a1, $sp, 0x20
/* 35BD78 E004E3A8 0C080114 */  jal       func_E0200450
/* 35BD7C E004E3AC 00A0302D */   daddu    $a2, $a1, $zero
/* 35BD80 E004E3B0 27A40020 */  addiu     $a0, $sp, 0x20
/* 35BD84 E004E3B4 3C108007 */  lui       $s0, 0x8007
/* 35BD88 E004E3B8 261041F0 */  addiu     $s0, $s0, 0x41f0
/* 35BD8C E004E3BC 3C12800A */  lui       $s2, 0x800a
/* 35BD90 E004E3C0 2652A674 */  addiu     $s2, $s2, -0x598c
/* 35BD94 E004E3C4 96050000 */  lhu       $a1, ($s0)
/* 35BD98 E004E3C8 8E420000 */  lw        $v0, ($s2)
/* 35BD9C E004E3CC 00052980 */  sll       $a1, $a1, 6
/* 35BDA0 E004E3D0 00B62821 */  addu      $a1, $a1, $s6
/* 35BDA4 E004E3D4 0C080118 */  jal       func_E0200460
/* 35BDA8 E004E3D8 00452821 */   addu     $a1, $v0, $a1
/* 35BDAC E004E3DC 3C07E200 */  lui       $a3, 0xe200
/* 35BDB0 E004E3E0 34E71E01 */  ori       $a3, $a3, 0x1e01
/* 35BDB4 E004E3E4 8EE80000 */  lw        $t0, ($s7)
/* 35BDB8 E004E3E8 3C03DA38 */  lui       $v1, 0xda38
/* 35BDBC E004E3EC 0100202D */  daddu     $a0, $t0, $zero
/* 35BDC0 E004E3F0 25080008 */  addiu     $t0, $t0, 8
/* 35BDC4 E004E3F4 AEE80000 */  sw        $t0, ($s7)
/* 35BDC8 E004E3F8 96020000 */  lhu       $v0, ($s0)
/* 35BDCC E004E3FC 327300FF */  andi      $s3, $s3, 0xff
/* 35BDD0 E004E400 AC830000 */  sw        $v1, ($a0)
/* 35BDD4 E004E404 24430001 */  addiu     $v1, $v0, 1
/* 35BDD8 E004E408 3042FFFF */  andi      $v0, $v0, 0xffff
/* 35BDDC E004E40C 00021180 */  sll       $v0, $v0, 6
/* 35BDE0 E004E410 A6030000 */  sh        $v1, ($s0)
/* 35BDE4 E004E414 8E430000 */  lw        $v1, ($s2)
/* 35BDE8 E004E418 00561021 */  addu      $v0, $v0, $s6
/* 35BDEC E004E41C 00621821 */  addu      $v1, $v1, $v0
/* 35BDF0 E004E420 25020008 */  addiu     $v0, $t0, 8
/* 35BDF4 E004E424 AC830004 */  sw        $v1, 4($a0)
/* 35BDF8 E004E428 AEE20000 */  sw        $v0, ($s7)
/* 35BDFC E004E42C 3C02FA00 */  lui       $v0, 0xfa00
/* 35BE00 E004E430 AD020000 */  sw        $v0, ($t0)
/* 35BE04 E004E434 92230024 */  lbu       $v1, 0x24($s1)
/* 35BE08 E004E438 92240025 */  lbu       $a0, 0x25($s1)
/* 35BE0C E004E43C 92250026 */  lbu       $a1, 0x26($s1)
/* 35BE10 E004E440 92260027 */  lbu       $a2, 0x27($s1)
/* 35BE14 E004E444 25020010 */  addiu     $v0, $t0, 0x10
/* 35BE18 E004E448 AEE20000 */  sw        $v0, ($s7)
/* 35BE1C E004E44C 3C02FB00 */  lui       $v0, 0xfb00
/* 35BE20 E004E450 AD020008 */  sw        $v0, 8($t0)
/* 35BE24 E004E454 25020018 */  addiu     $v0, $t0, 0x18
/* 35BE28 E004E458 AD13000C */  sw        $s3, 0xc($t0)
/* 35BE2C E004E45C AEE20000 */  sw        $v0, ($s7)
/* 35BE30 E004E460 24020003 */  addiu     $v0, $zero, 3
/* 35BE34 E004E464 AD020014 */  sw        $v0, 0x14($t0)
/* 35BE38 E004E468 25020020 */  addiu     $v0, $t0, 0x20
/* 35BE3C E004E46C AD070010 */  sw        $a3, 0x10($t0)
/* 35BE40 E004E470 AEE20000 */  sw        $v0, ($s7)
/* 35BE44 E004E474 001411C0 */  sll       $v0, $s4, 7
/* 35BE48 E004E478 30420FFF */  andi      $v0, $v0, 0xfff
/* 35BE4C E004E47C 00021300 */  sll       $v0, $v0, 0xc
/* 35BE50 E004E480 3C07F200 */  lui       $a3, 0xf200
/* 35BE54 E004E484 00471025 */  or        $v0, $v0, $a3
/* 35BE58 E004E488 0014A140 */  sll       $s4, $s4, 5
/* 35BE5C E004E48C AD020018 */  sw        $v0, 0x18($t0)
/* 35BE60 E004E490 2682001F */  addiu     $v0, $s4, 0x1f
/* 35BE64 E004E494 00021080 */  sll       $v0, $v0, 2
/* 35BE68 E004E498 30420FFF */  andi      $v0, $v0, 0xfff
/* 35BE6C E004E49C 00021300 */  sll       $v0, $v0, 0xc
/* 35BE70 E004E4A0 3442007C */  ori       $v0, $v0, 0x7c
/* 35BE74 E004E4A4 AD02001C */  sw        $v0, 0x1c($t0)
/* 35BE78 E004E4A8 00031E00 */  sll       $v1, $v1, 0x18
/* 35BE7C E004E4AC 00042400 */  sll       $a0, $a0, 0x10
/* 35BE80 E004E4B0 00641825 */  or        $v1, $v1, $a0
/* 35BE84 E004E4B4 00052A00 */  sll       $a1, $a1, 8
/* 35BE88 E004E4B8 00651825 */  or        $v1, $v1, $a1
/* 35BE8C E004E4BC 00661825 */  or        $v1, $v1, $a2
/* 35BE90 E004E4C0 26850020 */  addiu     $a1, $s4, 0x20
/* 35BE94 E004E4C4 12A00012 */  beqz      $s5, .LE004E510
/* 35BE98 E004E4C8 AD030004 */   sw       $v1, 4($t0)
/* 35BE9C E004E4CC 00E0182D */  daddu     $v1, $a3, $zero
/* 35BEA0 E004E4D0 34630080 */  ori       $v1, $v1, 0x80
/* 35BEA4 E004E4D4 3C040100 */  lui       $a0, 0x100
/* 35BEA8 E004E4D8 348400FC */  ori       $a0, $a0, 0xfc
/* 35BEAC E004E4DC 25020028 */  addiu     $v0, $t0, 0x28
/* 35BEB0 E004E4E0 AEE20000 */  sw        $v0, ($s7)
/* 35BEB4 E004E4E4 00051080 */  sll       $v0, $a1, 2
/* 35BEB8 E004E4E8 30420FFF */  andi      $v0, $v0, 0xfff
/* 35BEBC E004E4EC 00021300 */  sll       $v0, $v0, 0xc
/* 35BEC0 E004E4F0 00431025 */  or        $v0, $v0, $v1
/* 35BEC4 E004E4F4 AD020020 */  sw        $v0, 0x20($t0)
/* 35BEC8 E004E4F8 2682003F */  addiu     $v0, $s4, 0x3f
/* 35BECC E004E4FC 00021080 */  sll       $v0, $v0, 2
/* 35BED0 E004E500 30420FFF */  andi      $v0, $v0, 0xfff
/* 35BED4 E004E504 00021300 */  sll       $v0, $v0, 0xc
/* 35BED8 E004E508 08013952 */  j         .LE004E548
/* 35BEDC E004E50C 00441025 */   or       $v0, $v0, $a0
.LE004E510:
/* 35BEE0 E004E510 3C030100 */  lui       $v1, 0x100
/* 35BEE4 E004E514 3463007C */  ori       $v1, $v1, 0x7c
/* 35BEE8 E004E518 25020028 */  addiu     $v0, $t0, 0x28
/* 35BEEC E004E51C AEE20000 */  sw        $v0, ($s7)
/* 35BEF0 E004E520 00051080 */  sll       $v0, $a1, 2
/* 35BEF4 E004E524 30420FFF */  andi      $v0, $v0, 0xfff
/* 35BEF8 E004E528 00021300 */  sll       $v0, $v0, 0xc
/* 35BEFC E004E52C 00471025 */  or        $v0, $v0, $a3
/* 35BF00 E004E530 AD020020 */  sw        $v0, 0x20($t0)
/* 35BF04 E004E534 2682003F */  addiu     $v0, $s4, 0x3f
/* 35BF08 E004E538 00021080 */  sll       $v0, $v0, 2
/* 35BF0C E004E53C 30420FFF */  andi      $v0, $v0, 0xfff
/* 35BF10 E004E540 00021300 */  sll       $v0, $v0, 0xc
/* 35BF14 E004E544 00431025 */  or        $v0, $v0, $v1
.LE004E548:
/* 35BF18 E004E548 AD020024 */  sw        $v0, 0x24($t0)
/* 35BF1C E004E54C 3C06E200 */  lui       $a2, 0xe200
/* 35BF20 E004E550 34C61E01 */  ori       $a2, $a2, 0x1e01
/* 35BF24 E004E554 3C07D838 */  lui       $a3, 0xd838
/* 35BF28 E004E558 3C04800A */  lui       $a0, 0x800a
/* 35BF2C E004E55C 2484A66C */  addiu     $a0, $a0, -0x5994
/* 35BF30 E004E560 34E70002 */  ori       $a3, $a3, 2
/* 35BF34 E004E564 8C820000 */  lw        $v0, ($a0)
/* 35BF38 E004E568 3C03DE00 */  lui       $v1, 0xde00
/* 35BF3C E004E56C 0040282D */  daddu     $a1, $v0, $zero
/* 35BF40 E004E570 24420008 */  addiu     $v0, $v0, 8
/* 35BF44 E004E574 AC820000 */  sw        $v0, ($a0)
/* 35BF48 E004E578 ACA30000 */  sw        $v1, ($a1)
/* 35BF4C E004E57C 24430008 */  addiu     $v1, $v0, 8
/* 35BF50 E004E580 ACBE0004 */  sw        $fp, 4($a1)
/* 35BF54 E004E584 AC830000 */  sw        $v1, ($a0)
/* 35BF58 E004E588 24430010 */  addiu     $v1, $v0, 0x10
/* 35BF5C E004E58C AC460000 */  sw        $a2, ($v0)
/* 35BF60 E004E590 AC400004 */  sw        $zero, 4($v0)
/* 35BF64 E004E594 AC830000 */  sw        $v1, ($a0)
/* 35BF68 E004E598 24030040 */  addiu     $v1, $zero, 0x40
/* 35BF6C E004E59C AC470008 */  sw        $a3, 8($v0)
/* 35BF70 E004E5A0 AC43000C */  sw        $v1, 0xc($v0)
/* 35BF74 E004E5A4 8FBF00C4 */  lw        $ra, 0xc4($sp)
/* 35BF78 E004E5A8 8FBE00C0 */  lw        $fp, 0xc0($sp)
/* 35BF7C E004E5AC 8FB700BC */  lw        $s7, 0xbc($sp)
/* 35BF80 E004E5B0 8FB600B8 */  lw        $s6, 0xb8($sp)
/* 35BF84 E004E5B4 8FB500B4 */  lw        $s5, 0xb4($sp)
/* 35BF88 E004E5B8 8FB400B0 */  lw        $s4, 0xb0($sp)
/* 35BF8C E004E5BC 8FB300AC */  lw        $s3, 0xac($sp)
/* 35BF90 E004E5C0 8FB200A8 */  lw        $s2, 0xa8($sp)
/* 35BF94 E004E5C4 8FB100A4 */  lw        $s1, 0xa4($sp)
/* 35BF98 E004E5C8 8FB000A0 */  lw        $s0, 0xa0($sp)
/* 35BF9C E004E5CC D7B400C8 */  ldc1      $f20, 0xc8($sp)
/* 35BFA0 E004E5D0 03E00008 */  jr        $ra
/* 35BFA4 E004E5D4 27BD00D0 */   addiu    $sp, $sp, 0xd0
/* 35BFA8 E004E5D8 00000000 */  nop       
/* 35BFAC E004E5DC 00000000 */  nop       
