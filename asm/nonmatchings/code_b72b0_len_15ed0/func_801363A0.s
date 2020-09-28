.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_801363A0
/* CCAA0 801363A0 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* CCAA4 801363A4 AFB40038 */  sw        $s4, 0x38($sp)
/* CCAA8 801363A8 0080A02D */  daddu     $s4, $a0, $zero
/* CCAAC 801363AC AFBF003C */  sw        $ra, 0x3c($sp)
/* CCAB0 801363B0 AFB30034 */  sw        $s3, 0x34($sp)
/* CCAB4 801363B4 AFB20030 */  sw        $s2, 0x30($sp)
/* CCAB8 801363B8 AFB1002C */  sw        $s1, 0x2c($sp)
/* CCABC 801363BC AFB00028 */  sw        $s0, 0x28($sp)
/* CCAC0 801363C0 86820018 */  lh        $v0, 0x18($s4)
/* CCAC4 801363C4 3C038008 */  lui       $v1, %hi(gItemTable)
/* CCAC8 801363C8 246378E0 */  addiu     $v1, $v1, %lo(gItemTable)
/* CCACC 801363CC 00021140 */  sll       $v0, $v0, 5
/* CCAD0 801363D0 00432021 */  addu      $a0, $v0, $v1
/* CCAD4 801363D4 8283001A */  lb        $v1, 0x1a($s4)
/* CCAD8 801363D8 2402000A */  addiu     $v0, $zero, 0xa
/* CCADC 801363DC 1062000C */  beq       $v1, $v0, .L80136410
/* CCAE0 801363E0 2862000B */   slti     $v0, $v1, 0xb
/* CCAE4 801363E4 10400005 */  beqz      $v0, .L801363FC
/* CCAE8 801363E8 24020002 */   addiu    $v0, $zero, 2
/* CCAEC 801363EC 10620008 */  beq       $v1, $v0, .L80136410
/* CCAF0 801363F0 00000000 */   nop      
/* CCAF4 801363F4 0804D9C7 */  j         .L8013671C
/* CCAF8 801363F8 00000000 */   nop      
.L801363FC:
/* CCAFC 801363FC 2402000C */  addiu     $v0, $zero, 0xc
/* CCB00 80136400 106200AC */  beq       $v1, $v0, .L801366B4
/* CCB04 80136404 00000000 */   nop      
/* CCB08 80136408 0804D9C7 */  j         .L8013671C
/* CCB0C 8013640C 00000000 */   nop      
.L80136410:
/* CCB10 80136410 94820018 */  lhu       $v0, 0x18($a0)
/* CCB14 80136414 30420040 */  andi      $v0, $v0, 0x40
/* CCB18 80136418 1440003B */  bnez      $v0, .L80136508
/* CCB1C 8013641C 3C030400 */   lui      $v1, 0x400
/* CCB20 80136420 8E820000 */  lw        $v0, ($s4)
/* CCB24 80136424 00431024 */  and       $v0, $v0, $v1
/* CCB28 80136428 10400005 */  beqz      $v0, .L80136440
/* CCB2C 8013642C 3C12001D */   lui      $s2, 0x1d
/* CCB30 80136430 96820006 */  lhu       $v0, 6($s4)
/* CCB34 80136434 30420004 */  andi      $v0, $v0, 4
/* CCB38 80136438 50400002 */  beql      $v0, $zero, .L80136444
/* CCB3C 8013643C 3652005A */   ori      $s2, $s2, 0x5a
.L80136440:
/* CCB40 80136440 36520058 */  ori       $s2, $s2, 0x58
.L80136444:
/* CCB44 80136444 96830006 */  lhu       $v1, 6($s4)
/* CCB48 80136448 30620010 */  andi      $v0, $v1, 0x10
/* CCB4C 8013644C 10400003 */  beqz      $v0, .L8013645C
/* CCB50 80136450 30620020 */   andi     $v0, $v1, 0x20
/* CCB54 80136454 3C12001D */  lui       $s2, 0x1d
/* CCB58 80136458 3652005D */  ori       $s2, $s2, 0x5d
.L8013645C:
/* CCB5C 8013645C 10400003 */  beqz      $v0, .L8013646C
/* CCB60 80136460 30620040 */   andi     $v0, $v1, 0x40
/* CCB64 80136464 3C12001D */  lui       $s2, 0x1d
/* CCB68 80136468 3652005E */  ori       $s2, $s2, 0x5e
.L8013646C:
/* CCB6C 8013646C 10400003 */  beqz      $v0, .L8013647C
/* CCB70 80136470 00000000 */   nop      
/* CCB74 80136474 3C12001D */  lui       $s2, 0x1d
/* CCB78 80136478 3652005C */  ori       $s2, $s2, 0x5c
.L8013647C:
/* CCB7C 8013647C 8C840000 */  lw        $a0, ($a0)
/* CCB80 80136480 0C0496CF */  jal       set_message_string
/* CCB84 80136484 0000282D */   daddu    $a1, $zero, $zero
/* CCB88 80136488 86840018 */  lh        $a0, 0x18($s4)
/* CCB8C 8013648C 00041140 */  sll       $v0, $a0, 5
/* CCB90 80136490 3C038008 */  lui       $v1, 0x8008
/* CCB94 80136494 00621821 */  addu      $v1, $v1, $v0
/* CCB98 80136498 946378F8 */  lhu       $v1, 0x78f8($v1)
/* CCB9C 8013649C 30620008 */  andi      $v0, $v1, 8
/* CCBA0 801364A0 5440000F */  bnel      $v0, $zero, .L801364E0
/* CCBA4 801364A4 0240202D */   daddu    $a0, $s2, $zero
/* CCBA8 801364A8 2402015C */  addiu     $v0, $zero, 0x15c
/* CCBAC 801364AC 1082000B */  beq       $a0, $v0, .L801364DC
/* CCBB0 801364B0 30620020 */   andi     $v0, $v1, 0x20
/* CCBB4 801364B4 1440000A */  bnez      $v0, .L801364E0
/* CCBB8 801364B8 0240202D */   daddu    $a0, $s2, $zero
/* CCBBC 801364BC 96820006 */  lhu       $v0, 6($s4)
/* CCBC0 801364C0 30420030 */  andi      $v0, $v0, 0x30
/* CCBC4 801364C4 14400006 */  bnez      $v0, .L801364E0
/* CCBC8 801364C8 00000000 */   nop      
/* CCBCC 801364CC 0C04991D */  jal       get_string_width
/* CCBD0 801364D0 0000282D */   daddu    $a1, $zero, $zero
/* CCBD4 801364D4 0804D93B */  j         .L801364EC
/* CCBD8 801364D8 24500036 */   addiu    $s0, $v0, 0x36
.L801364DC:
/* CCBDC 801364DC 0240202D */  daddu     $a0, $s2, $zero
.L801364E0:
/* CCBE0 801364E0 0C04991D */  jal       get_string_width
/* CCBE4 801364E4 0000282D */   daddu    $a1, $zero, $zero
/* CCBE8 801364E8 2450001E */  addiu     $s0, $v0, 0x1e
.L801364EC:
/* CCBEC 801364EC 001017C2 */  srl       $v0, $s0, 0x1f
/* CCBF0 801364F0 02021021 */  addu      $v0, $s0, $v0
/* CCBF4 801364F4 00021043 */  sra       $v0, $v0, 1
/* CCBF8 801364F8 240300A0 */  addiu     $v1, $zero, 0xa0
/* CCBFC 801364FC 00628823 */  subu      $s1, $v1, $v0
/* CCC00 80136500 0804D966 */  j         .L80136598
/* CCC04 80136504 2413004C */   addiu    $s3, $zero, 0x4c
.L80136508:
/* CCC08 80136508 8E820000 */  lw        $v0, ($s4)
/* CCC0C 8013650C 00431024 */  and       $v0, $v0, $v1
/* CCC10 80136510 10400005 */  beqz      $v0, .L80136528
/* CCC14 80136514 3C12001D */   lui      $s2, 0x1d
/* CCC18 80136518 96820006 */  lhu       $v0, 6($s4)
/* CCC1C 8013651C 30420004 */  andi      $v0, $v0, 4
/* CCC20 80136520 50400002 */  beql      $v0, $zero, .L8013652C
/* CCC24 80136524 3652005B */   ori      $s2, $s2, 0x5b
.L80136528:
/* CCC28 80136528 36520059 */  ori       $s2, $s2, 0x59
.L8013652C:
/* CCC2C 8013652C 96830006 */  lhu       $v1, 6($s4)
/* CCC30 80136530 30620010 */  andi      $v0, $v1, 0x10
/* CCC34 80136534 10400003 */  beqz      $v0, .L80136544
/* CCC38 80136538 30620020 */   andi     $v0, $v1, 0x20
/* CCC3C 8013653C 3C12001D */  lui       $s2, 0x1d
/* CCC40 80136540 3652005D */  ori       $s2, $s2, 0x5d
.L80136544:
/* CCC44 80136544 10400003 */  beqz      $v0, .L80136554
/* CCC48 80136548 30620040 */   andi     $v0, $v1, 0x40
/* CCC4C 8013654C 3C12001D */  lui       $s2, 0x1d
/* CCC50 80136550 3652005E */  ori       $s2, $s2, 0x5e
.L80136554:
/* CCC54 80136554 10400003 */  beqz      $v0, .L80136564
/* CCC58 80136558 00000000 */   nop      
/* CCC5C 8013655C 3C12001D */  lui       $s2, 0x1d
/* CCC60 80136560 3652005C */  ori       $s2, $s2, 0x5c
.L80136564:
/* CCC64 80136564 8C840000 */  lw        $a0, ($a0)
/* CCC68 80136568 0000282D */  daddu     $a1, $zero, $zero
/* CCC6C 8013656C 0C0496CF */  jal       set_message_string
/* CCC70 80136570 2413004C */   addiu    $s3, $zero, 0x4c
/* CCC74 80136574 0240202D */  daddu     $a0, $s2, $zero
/* CCC78 80136578 0C04991D */  jal       get_string_width
/* CCC7C 8013657C 0000282D */   daddu    $a1, $zero, $zero
/* CCC80 80136580 2450001E */  addiu     $s0, $v0, 0x1e
/* CCC84 80136584 001017C2 */  srl       $v0, $s0, 0x1f
/* CCC88 80136588 02021021 */  addu      $v0, $s0, $v0
/* CCC8C 8013658C 00021043 */  sra       $v0, $v0, 1
/* CCC90 80136590 240300A0 */  addiu     $v1, $zero, 0xa0
/* CCC94 80136594 00628823 */  subu      $s1, $v1, $v0
.L80136598:
/* CCC98 80136598 0C04992C */  jal       func_801264B0
/* CCC9C 8013659C 0240202D */   daddu    $a0, $s2, $zero
/* CCCA0 801365A0 2442FFFF */  addiu     $v0, $v0, -1
/* CCCA4 801365A4 00021040 */  sll       $v0, $v0, 1
/* CCCA8 801365A8 24040002 */  addiu     $a0, $zero, 2
/* CCCAC 801365AC 8283001A */  lb        $v1, 0x1a($s4)
/* CCCB0 801365B0 3C088015 */  lui       $t0, 0x8015
/* CCCB4 801365B4 01024021 */  addu      $t0, $t0, $v0
/* CCCB8 801365B8 8508C6E0 */  lh        $t0, -0x3920($t0)
/* CCCBC 801365BC 10640002 */  beq       $v1, $a0, .L801365C8
/* CCCC0 801365C0 0000302D */   daddu    $a2, $zero, $zero
/* CCCC4 801365C4 2406001C */  addiu     $a2, $zero, 0x1c
.L801365C8:
/* CCCC8 801365C8 86840018 */  lh        $a0, 0x18($s4)
/* CCCCC 801365CC 00041140 */  sll       $v0, $a0, 5
/* CCCD0 801365D0 3C038008 */  lui       $v1, 0x8008
/* CCCD4 801365D4 00621821 */  addu      $v1, $v1, $v0
/* CCCD8 801365D8 946378F8 */  lhu       $v1, 0x78f8($v1)
/* CCCDC 801365DC 2404000C */  addiu     $a0, $zero, 0xc
/* CCCE0 801365E0 0220282D */  daddu     $a1, $s1, $zero
/* CCCE4 801365E4 24C6FFE8 */  addiu     $a2, $a2, -0x18
/* CCCE8 801365E8 02663021 */  addu      $a2, $s3, $a2
/* CCCEC 801365EC 0200382D */  daddu     $a3, $s0, $zero
/* CCCF0 801365F0 3C028013 */  lui       $v0, 0x8013
/* CCCF4 801365F4 2442673C */  addiu     $v0, $v0, 0x673c
/* CCCF8 801365F8 AFA20018 */  sw        $v0, 0x18($sp)
/* CCCFC 801365FC 2402FFFF */  addiu     $v0, $zero, -1
/* CCD00 80136600 AFA80010 */  sw        $t0, 0x10($sp)
/* CCD04 80136604 AFA00014 */  sw        $zero, 0x14($sp)
/* CCD08 80136608 AFB4001C */  sw        $s4, 0x1c($sp)
/* CCD0C 8013660C 0C051F32 */  jal       set_ui_panel_properties
/* CCD10 80136610 AFA20020 */   sw       $v0, 0x20($sp)
/* CCD14 80136614 86830018 */  lh        $v1, 0x18($s4)
/* CCD18 80136618 2402015C */  addiu     $v0, $zero, 0x15c
/* CCD1C 8013661C 10620010 */  beq       $v1, $v0, .L80136660
/* CCD20 80136620 24020157 */   addiu    $v0, $zero, 0x157
/* CCD24 80136624 1062000E */  beq       $v1, $v0, .L80136660
/* CCD28 80136628 24040013 */   addiu    $a0, $zero, 0x13
/* CCD2C 8013662C 24050014 */  addiu     $a1, $zero, 0x14
/* CCD30 80136630 240600BA */  addiu     $a2, $zero, 0xba
/* CCD34 80136634 24070118 */  addiu     $a3, $zero, 0x118
/* CCD38 80136638 24020020 */  addiu     $v0, $zero, 0x20
/* CCD3C 8013663C AFA20010 */  sw        $v0, 0x10($sp)
/* CCD40 80136640 3C028013 */  lui       $v0, 0x8013
/* CCD44 80136644 24426A08 */  addiu     $v0, $v0, 0x6a08
/* CCD48 80136648 AFA20018 */  sw        $v0, 0x18($sp)
/* CCD4C 8013664C 2402FFFF */  addiu     $v0, $zero, -1
/* CCD50 80136650 AFA00014 */  sw        $zero, 0x14($sp)
/* CCD54 80136654 AFB4001C */  sw        $s4, 0x1c($sp)
/* CCD58 80136658 0C051F32 */  jal       set_ui_panel_properties
/* CCD5C 8013665C AFA20020 */   sw       $v0, 0x20($sp)
.L80136660:
/* CCD60 80136660 8283001A */  lb        $v1, 0x1a($s4)
/* CCD64 80136664 24020002 */  addiu     $v0, $zero, 2
/* CCD68 80136668 1062002C */  beq       $v1, $v0, .L8013671C
/* CCD6C 8013666C 3C04001D */   lui      $a0, 0x1d
/* CCD70 80136670 34840060 */  ori       $a0, $a0, 0x60
/* CCD74 80136674 0C04991D */  jal       get_string_width
/* CCD78 80136678 0000282D */   daddu    $a1, $zero, $zero
/* CCD7C 8013667C 24500018 */  addiu     $s0, $v0, 0x18
/* CCD80 80136680 24040011 */  addiu     $a0, $zero, 0x11
/* CCD84 80136684 00102FC2 */  srl       $a1, $s0, 0x1f
/* CCD88 80136688 02052821 */  addu      $a1, $s0, $a1
/* CCD8C 8013668C 00052843 */  sra       $a1, $a1, 1
/* CCD90 80136690 240200A0 */  addiu     $v0, $zero, 0xa0
/* CCD94 80136694 00452823 */  subu      $a1, $v0, $a1
/* CCD98 80136698 24060024 */  addiu     $a2, $zero, 0x24
/* CCD9C 8013669C 24020028 */  addiu     $v0, $zero, 0x28
/* CCDA0 801366A0 AFA20010 */  sw        $v0, 0x10($sp)
/* CCDA4 801366A4 3C028013 */  lui       $v0, 0x8013
/* CCDA8 801366A8 244269D0 */  addiu     $v0, $v0, 0x69d0
/* CCDAC 801366AC 0804D9C1 */  j         .L80136704
/* CCDB0 801366B0 0200382D */   daddu    $a3, $s0, $zero
.L801366B4:
/* CCDB4 801366B4 8C840000 */  lw        $a0, ($a0)
/* CCDB8 801366B8 0C0496CF */  jal       set_message_string
/* CCDBC 801366BC 0000282D */   daddu    $a1, $zero, $zero
/* CCDC0 801366C0 3C04001D */  lui       $a0, 0x1d
/* CCDC4 801366C4 3484005F */  ori       $a0, $a0, 0x5f
/* CCDC8 801366C8 0C04991D */  jal       get_string_width
/* CCDCC 801366CC 0000282D */   daddu    $a1, $zero, $zero
/* CCDD0 801366D0 24500036 */  addiu     $s0, $v0, 0x36
/* CCDD4 801366D4 2404000C */  addiu     $a0, $zero, 0xc
/* CCDD8 801366D8 00102FC2 */  srl       $a1, $s0, 0x1f
/* CCDDC 801366DC 02052821 */  addu      $a1, $s0, $a1
/* CCDE0 801366E0 00052843 */  sra       $a1, $a1, 1
/* CCDE4 801366E4 240200A0 */  addiu     $v0, $zero, 0xa0
/* CCDE8 801366E8 00452823 */  subu      $a1, $v0, $a1
/* CCDEC 801366EC 2406004C */  addiu     $a2, $zero, 0x4c
/* CCDF0 801366F0 0200382D */  daddu     $a3, $s0, $zero
/* CCDF4 801366F4 24020028 */  addiu     $v0, $zero, 0x28
/* CCDF8 801366F8 AFA20010 */  sw        $v0, 0x10($sp)
/* CCDFC 801366FC 3C028013 */  lui       $v0, 0x8013
/* CCE00 80136700 2442673C */  addiu     $v0, $v0, 0x673c
.L80136704:
/* CCE04 80136704 AFA20018 */  sw        $v0, 0x18($sp)
/* CCE08 80136708 2402FFFF */  addiu     $v0, $zero, -1
/* CCE0C 8013670C AFA00014 */  sw        $zero, 0x14($sp)
/* CCE10 80136710 AFB4001C */  sw        $s4, 0x1c($sp)
/* CCE14 80136714 0C051F32 */  jal       set_ui_panel_properties
/* CCE18 80136718 AFA20020 */   sw       $v0, 0x20($sp)
.L8013671C:
/* CCE1C 8013671C 8FBF003C */  lw        $ra, 0x3c($sp)
/* CCE20 80136720 8FB40038 */  lw        $s4, 0x38($sp)
/* CCE24 80136724 8FB30034 */  lw        $s3, 0x34($sp)
/* CCE28 80136728 8FB20030 */  lw        $s2, 0x30($sp)
/* CCE2C 8013672C 8FB1002C */  lw        $s1, 0x2c($sp)
/* CCE30 80136730 8FB00028 */  lw        $s0, 0x28($sp)
/* CCE34 80136734 03E00008 */  jr        $ra
/* CCE38 80136738 27BD0040 */   addiu    $sp, $sp, 0x40
