.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D6420
/* FADD0 802D6420 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* FADD4 802D6424 AFB00010 */  sw        $s0, 0x10($sp)
/* FADD8 802D6428 0080802D */  daddu     $s0, $a0, $zero
/* FADDC 802D642C AFB3001C */  sw        $s3, 0x1c($sp)
/* FADE0 802D6430 3C138011 */  lui       $s3, %hi(gPlayerData)
/* FADE4 802D6434 2673F290 */  addiu     $s3, $s3, %lo(gPlayerData)
/* FADE8 802D6438 AFB10014 */  sw        $s1, 0x14($sp)
/* FADEC 802D643C 3C11802E */  lui       $s1, %hi(D_802DB830)
/* FADF0 802D6440 2631B830 */  addiu     $s1, $s1, %lo(D_802DB830)
/* FADF4 802D6444 AFBF0020 */  sw        $ra, 0x20($sp)
/* FADF8 802D6448 AFB20018 */  sw        $s2, 0x18($sp)
/* FADFC 802D644C 8E12014C */  lw        $s2, 0x14c($s0)
/* FAE00 802D6450 54A00001 */  bnel      $a1, $zero, .L802D6458
/* FAE04 802D6454 AE000070 */   sw       $zero, 0x70($s0)
.L802D6458:
/* FAE08 802D6458 8E030070 */  lw        $v1, 0x70($s0)
/* FAE0C 802D645C 10600005 */  beqz      $v1, .L802D6474
/* FAE10 802D6460 24020001 */   addiu    $v0, $zero, 1
/* FAE14 802D6464 1062004B */  beq       $v1, $v0, .L802D6594
/* FAE18 802D6468 0000102D */   daddu    $v0, $zero, $zero
/* FAE1C 802D646C 080B5988 */  j         .L802D6620
/* FAE20 802D6470 00000000 */   nop
.L802D6474:
/* FAE24 802D6474 0C03805E */  jal       disable_player_input
/* FAE28 802D6478 00000000 */   nop
/* FAE2C 802D647C 0C038045 */  jal       disable_player_static_collisions
/* FAE30 802D6480 00000000 */   nop
/* FAE34 802D6484 0C03BD8A */  jal       func_800EF628
/* FAE38 802D6488 00000000 */   nop
/* FAE3C 802D648C 0C03A5EE */  jal       func_800E97B8
/* FAE40 802D6490 00000000 */   nop
/* FAE44 802D6494 0000482D */  daddu     $t1, $zero, $zero
/* FAE48 802D6498 0120402D */  daddu     $t0, $t1, $zero
/* FAE4C 802D649C 3C0C8008 */  lui       $t4, %hi(gItemTable)
/* FAE50 802D64A0 258C78E0 */  addiu     $t4, $t4, %lo(gItemTable)
/* FAE54 802D64A4 3C0B8009 */  lui       $t3, %hi(D_8008A680)
/* FAE58 802D64A8 256BA680 */  addiu     $t3, $t3, %lo(D_8008A680)
/* FAE5C 802D64AC 240A0001 */  addiu     $t2, $zero, 1
/* FAE60 802D64B0 0260382D */  daddu     $a3, $s3, $zero
/* FAE64 802D64B4 3C03800A */  lui       $v1, %hi(D_8009A650)
/* FAE68 802D64B8 2463A650 */  addiu     $v1, $v1, %lo(D_8009A650)
/* FAE6C 802D64BC 8C620000 */  lw        $v0, ($v1)
/* FAE70 802D64C0 0220302D */  daddu     $a2, $s1, $zero
/* FAE74 802D64C4 34420040 */  ori       $v0, $v0, 0x40
/* FAE78 802D64C8 AC620000 */  sw        $v0, ($v1)
.L802D64CC:
/* FAE7C 802D64CC 84E40074 */  lh        $a0, 0x74($a3)
/* FAE80 802D64D0 5080001F */  beql      $a0, $zero, .L802D6550
/* FAE84 802D64D4 25080001 */   addiu    $t0, $t0, 1
/* FAE88 802D64D8 8E430028 */  lw        $v1, 0x28($s2)
/* FAE8C 802D64DC 8C620000 */  lw        $v0, ($v1)
/* FAE90 802D64E0 18400008 */  blez      $v0, .L802D6504
/* FAE94 802D64E4 0000282D */   daddu    $a1, $zero, $zero
.L802D64E8:
/* FAE98 802D64E8 54820003 */  bnel      $a0, $v0, .L802D64F8
/* FAE9C 802D64EC 24630004 */   addiu    $v1, $v1, 4
/* FAEA0 802D64F0 080B5941 */  j         .L802D6504
/* FAEA4 802D64F4 24050001 */   addiu    $a1, $zero, 1
.L802D64F8:
/* FAEA8 802D64F8 8C620000 */  lw        $v0, ($v1)
/* FAEAC 802D64FC 1C40FFFA */  bgtz      $v0, .L802D64E8
/* FAEB0 802D6500 00000000 */   nop
.L802D6504:
/* FAEB4 802D6504 50A00012 */  beql      $a1, $zero, .L802D6550
/* FAEB8 802D6508 25080001 */   addiu    $t0, $t0, 1
/* FAEBC 802D650C 84E30074 */  lh        $v1, 0x74($a3)
/* FAEC0 802D6510 00031940 */  sll       $v1, $v1, 5
/* FAEC4 802D6514 006C1821 */  addu      $v1, $v1, $t4
/* FAEC8 802D6518 84620004 */  lh        $v0, 4($v1)
/* FAECC 802D651C 000210C0 */  sll       $v0, $v0, 3
/* FAED0 802D6520 004B1021 */  addu      $v0, $v0, $t3
/* FAED4 802D6524 8C420000 */  lw        $v0, ($v0)
/* FAED8 802D6528 ACC80108 */  sw        $t0, 0x108($a2)
/* FAEDC 802D652C ACCA018C */  sw        $t2, 0x18c($a2)
/* FAEE0 802D6530 ACC20000 */  sw        $v0, ($a2)
/* FAEE4 802D6534 8C620000 */  lw        $v0, ($v1)
/* FAEE8 802D6538 ACC20084 */  sw        $v0, 0x84($a2)
/* FAEEC 802D653C 8C620014 */  lw        $v0, 0x14($v1)
/* FAEF0 802D6540 25290001 */  addiu     $t1, $t1, 1
/* FAEF4 802D6544 ACC20294 */  sw        $v0, 0x294($a2)
/* FAEF8 802D6548 24C60004 */  addiu     $a2, $a2, 4
/* FAEFC 802D654C 25080001 */  addiu     $t0, $t0, 1
.L802D6550:
/* FAF00 802D6550 29020020 */  slti      $v0, $t0, 0x20
/* FAF04 802D6554 1440FFDD */  bnez      $v0, .L802D64CC
/* FAF08 802D6558 24E70002 */   addiu    $a3, $a3, 2
/* FAF0C 802D655C 15200004 */  bnez      $t1, .L802D6570
/* FAF10 802D6560 2402000C */   addiu    $v0, $zero, 0xc
/* FAF14 802D6564 AE000084 */  sw        $zero, 0x84($s0)
/* FAF18 802D6568 080B5988 */  j         .L802D6620
/* FAF1C 802D656C 24020001 */   addiu    $v0, $zero, 1
.L802D6570:
/* FAF20 802D6570 0220202D */  daddu     $a0, $s1, $zero
/* FAF24 802D6574 AE220318 */  sw        $v0, 0x318($s1)
/* FAF28 802D6578 AE290324 */  sw        $t1, 0x324($s1)
/* FAF2C 802D657C 0C03D390 */  jal       func_800F4E40
/* FAF30 802D6580 AE200328 */   sw       $zero, 0x328($s1)
/* FAF34 802D6584 24020001 */  addiu     $v0, $zero, 1
/* FAF38 802D6588 AE000074 */  sw        $zero, 0x74($s0)
/* FAF3C 802D658C 080B5987 */  j         .L802D661C
/* FAF40 802D6590 AE020070 */   sw       $v0, 0x70($s0)
.L802D6594:
/* FAF44 802D6594 8E020074 */  lw        $v0, 0x74($s0)
/* FAF48 802D6598 14400008 */  bnez      $v0, .L802D65BC
/* FAF4C 802D659C 24420001 */   addiu    $v0, $v0, 1
/* FAF50 802D65A0 8622032C */  lh        $v0, 0x32c($s1)
/* FAF54 802D65A4 1040001D */  beqz      $v0, .L802D661C
/* FAF58 802D65A8 AE020078 */   sw       $v0, 0x78($s0)
/* FAF5C 802D65AC 0C03C4EC */  jal       func_800F13B0
/* FAF60 802D65B0 00000000 */   nop
/* FAF64 802D65B4 8E020074 */  lw        $v0, 0x74($s0)
/* FAF68 802D65B8 24420001 */  addiu     $v0, $v0, 1
.L802D65BC:
/* FAF6C 802D65BC AE020074 */  sw        $v0, 0x74($s0)
/* FAF70 802D65C0 2842000F */  slti      $v0, $v0, 0xf
/* FAF74 802D65C4 14400016 */  bnez      $v0, .L802D6620
/* FAF78 802D65C8 0000102D */   daddu    $v0, $zero, $zero
/* FAF7C 802D65CC 0C03C54E */  jal       func_800F1538
/* FAF80 802D65D0 00000000 */   nop
/* FAF84 802D65D4 8E030078 */  lw        $v1, 0x78($s0)
/* FAF88 802D65D8 240200FF */  addiu     $v0, $zero, 0xff
/* FAF8C 802D65DC 54620005 */  bnel      $v1, $v0, .L802D65F4
/* FAF90 802D65E0 2462FFFF */   addiu    $v0, $v1, -1
/* FAF94 802D65E4 2402FFFF */  addiu     $v0, $zero, -1
/* FAF98 802D65E8 AE020084 */  sw        $v0, 0x84($s0)
/* FAF9C 802D65EC 080B5988 */  j         .L802D6620
/* FAFA0 802D65F0 24020001 */   addiu    $v0, $zero, 1
.L802D65F4:
/* FAFA4 802D65F4 00021080 */  sll       $v0, $v0, 2
/* FAFA8 802D65F8 00511021 */  addu      $v0, $v0, $s1
/* FAFAC 802D65FC 8C430108 */  lw        $v1, 0x108($v0)
/* FAFB0 802D6600 00031040 */  sll       $v0, $v1, 1
/* FAFB4 802D6604 00531021 */  addu      $v0, $v0, $s3
/* FAFB8 802D6608 AE030088 */  sw        $v1, 0x88($s0)
/* FAFBC 802D660C 84430074 */  lh        $v1, 0x74($v0)
/* FAFC0 802D6610 24020001 */  addiu     $v0, $zero, 1
/* FAFC4 802D6614 080B5988 */  j         .L802D6620
/* FAFC8 802D6618 AE030084 */   sw       $v1, 0x84($s0)
.L802D661C:
/* FAFCC 802D661C 0000102D */  daddu     $v0, $zero, $zero
.L802D6620:
/* FAFD0 802D6620 8FBF0020 */  lw        $ra, 0x20($sp)
/* FAFD4 802D6624 8FB3001C */  lw        $s3, 0x1c($sp)
/* FAFD8 802D6628 8FB20018 */  lw        $s2, 0x18($sp)
/* FAFDC 802D662C 8FB10014 */  lw        $s1, 0x14($sp)
/* FAFE0 802D6630 8FB00010 */  lw        $s0, 0x10($sp)
/* FAFE4 802D6634 03E00008 */  jr        $ra
/* FAFE8 802D6638 27BD0028 */   addiu    $sp, $sp, 0x28
