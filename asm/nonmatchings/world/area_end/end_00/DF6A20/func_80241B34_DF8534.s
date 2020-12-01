.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241B34_DF8534
/* DF8534 80241B34 27BDFF80 */  addiu     $sp, $sp, -0x80
/* DF8538 80241B38 AFB30064 */  sw        $s3, 0x64($sp)
/* DF853C 80241B3C 0080982D */  daddu     $s3, $a0, $zero
/* DF8540 80241B40 AFBE0078 */  sw        $fp, 0x78($sp)
/* DF8544 80241B44 0000F02D */  daddu     $fp, $zero, $zero
/* DF8548 80241B48 AFBF007C */  sw        $ra, 0x7c($sp)
/* DF854C 80241B4C AFB70074 */  sw        $s7, 0x74($sp)
/* DF8550 80241B50 AFB60070 */  sw        $s6, 0x70($sp)
/* DF8554 80241B54 AFB5006C */  sw        $s5, 0x6c($sp)
/* DF8558 80241B58 AFB40068 */  sw        $s4, 0x68($sp)
/* DF855C 80241B5C AFB20060 */  sw        $s2, 0x60($sp)
/* DF8560 80241B60 AFB1005C */  sw        $s1, 0x5c($sp)
/* DF8564 80241B64 AFB00058 */  sw        $s0, 0x58($sp)
/* DF8568 80241B68 96630070 */  lhu       $v1, 0x70($s3)
/* DF856C 80241B6C 30620002 */  andi      $v0, $v1, 2
/* DF8570 80241B70 10400005 */  beqz      $v0, .L80241B88
/* DF8574 80241B74 27B00020 */   addiu    $s0, $sp, 0x20
/* DF8578 80241B78 3062FFFD */  andi      $v0, $v1, 0xfffd
/* DF857C 80241B7C A6620070 */  sh        $v0, 0x70($s3)
/* DF8580 80241B80 AE600008 */  sw        $zero, 8($s3)
/* DF8584 80241B84 AE60000C */  sw        $zero, 0xc($s3)
.L80241B88:
/* DF8588 80241B88 27A50040 */  addiu     $a1, $sp, 0x40
/* DF858C 80241B8C 27A60044 */  addiu     $a2, $sp, 0x44
/* DF8590 80241B90 27A70048 */  addiu     $a3, $sp, 0x48
/* DF8594 80241B94 0000882D */  daddu     $s1, $zero, $zero
/* DF8598 80241B98 AFA00010 */  sw        $zero, 0x10($sp)
/* DF859C 80241B9C AFA00014 */  sw        $zero, 0x14($sp)
/* DF85A0 80241BA0 AFA00018 */  sw        $zero, 0x18($sp)
/* DF85A4 80241BA4 AFA0001C */  sw        $zero, 0x1c($sp)
/* DF85A8 80241BA8 8E640000 */  lw        $a0, ($s3)
/* DF85AC 80241BAC 0C0497DA */  jal       get_string_properties
/* DF85B0 80241BB0 24170008 */   addiu    $s7, $zero, 8
/* DF85B4 80241BB4 24020001 */  addiu     $v0, $zero, 1
/* DF85B8 80241BB8 AFA00024 */  sw        $zero, 0x24($sp)
/* DF85BC 80241BBC AFA00028 */  sw        $zero, 0x28($sp)
/* DF85C0 80241BC0 AFA20044 */  sw        $v0, 0x44($sp)
.L80241BC4:
/* DF85C4 80241BC4 8E620000 */  lw        $v0, ($s3)
/* DF85C8 80241BC8 00511821 */  addu      $v1, $v0, $s1
/* DF85CC 80241BCC 26310001 */  addiu     $s1, $s1, 1
/* DF85D0 80241BD0 00511021 */  addu      $v0, $v0, $s1
/* DF85D4 80241BD4 90740000 */  lbu       $s4, ($v1)
/* DF85D8 80241BD8 90550000 */  lbu       $s5, ($v0)
/* DF85DC 80241BDC 2684FF10 */  addiu     $a0, $s4, -0xf0
/* DF85E0 80241BE0 2C830010 */  sltiu     $v1, $a0, 0x10
/* DF85E4 80241BE4 10600017 */  beqz      $v1, .L80241C44
/* DF85E8 80241BE8 0000B02D */   daddu    $s6, $zero, $zero
/* DF85EC 80241BEC 00041080 */  sll       $v0, $a0, 2
/* DF85F0 80241BF0 3C098025 */  lui       $t1, %hi(D_8024E8C0)
/* DF85F4 80241BF4 2529E8C0 */  addiu     $t1, $t1, %lo(D_8024E8C0)
/* DF85F8 80241BF8 00491021 */  addu      $v0, $v0, $t1
/* DF85FC 80241BFC 8C420000 */  lw        $v0, ($v0)
/* DF8600 80241C00 00400008 */  jr        $v0
/* DF8604 80241C04 00000000 */   nop      
/* DF8608 80241C08 2682FF0D */  addiu     $v0, $s4, -0xf3
/* DF860C 80241C0C 08090743 */  j         .L80241D0C
/* DF8610 80241C10 AE020008 */   sw       $v0, 8($s0)
/* DF8614 80241C14 08090743 */  j         .L80241D0C
/* DF8618 80241C18 24160001 */   addiu    $s6, $zero, 1
/* DF861C 80241C1C 8E630000 */  lw        $v1, ($s3)
/* DF8620 80241C20 00711021 */  addu      $v0, $v1, $s1
/* DF8624 80241C24 90420000 */  lbu       $v0, ($v0)
/* DF8628 80241C28 14400038 */  bnez      $v0, .L80241D0C
/* DF862C 80241C2C 26310001 */   addiu    $s1, $s1, 1
/* DF8630 80241C30 00711021 */  addu      $v0, $v1, $s1
/* DF8634 80241C34 90420000 */  lbu       $v0, ($v0)
/* DF8638 80241C38 26310001 */  addiu     $s1, $s1, 1
/* DF863C 80241C3C 08090743 */  j         .L80241D0C
/* DF8640 80241C40 AE020004 */   sw       $v0, 4($s0)
.L80241C44:
/* DF8644 80241C44 24020001 */  addiu     $v0, $zero, 1
/* DF8648 80241C48 329200FF */  andi      $s2, $s4, 0xff
/* DF864C 80241C4C AFA00010 */  sw        $zero, 0x10($sp)
/* DF8650 80241C50 AFA20014 */  sw        $v0, 0x14($sp)
/* DF8654 80241C54 8E050004 */  lw        $a1, 4($s0)
/* DF8658 80241C58 8E060008 */  lw        $a2, 8($s0)
/* DF865C 80241C5C 3C073F80 */  lui       $a3, 0x3f80
/* DF8660 80241C60 0C049721 */  jal       func_80125C84
/* DF8664 80241C64 0240202D */   daddu    $a0, $s2, $zero
/* DF8668 80241C68 8FA30044 */  lw        $v1, 0x44($sp)
/* DF866C 80241C6C 8E040004 */  lw        $a0, 4($s0)
/* DF8670 80241C70 2463FFFF */  addiu     $v1, $v1, -1
/* DF8674 80241C74 00621821 */  addu      $v1, $v1, $v0
/* DF8678 80241C78 2482FFFD */  addiu     $v0, $a0, -3
/* DF867C 80241C7C 2C420002 */  sltiu     $v0, $v0, 2
/* DF8680 80241C80 10400022 */  beqz      $v0, .L80241D0C
/* DF8684 80241C84 AFA30044 */   sw       $v1, 0x44($sp)
/* DF8688 80241C88 3C058024 */  lui       $a1, %hi(D_80242CD8)
/* DF868C 80241C8C 24A52CD8 */  addiu     $a1, $a1, %lo(D_80242CD8)
/* DF8690 80241C90 24090004 */  addiu     $t1, $zero, 4
/* DF8694 80241C94 14890003 */  bne       $a0, $t1, .L80241CA4
/* DF8698 80241C98 00000000 */   nop      
/* DF869C 80241C9C 3C058024 */  lui       $a1, %hi(D_80242C70)
/* DF86A0 80241CA0 24A52C70 */  addiu     $a1, $a1, %lo(D_80242C70)
.L80241CA4:
/* DF86A4 80241CA4 14890007 */  bne       $a0, $t1, .L80241CC4
/* DF86A8 80241CA8 0000302D */   daddu    $a2, $zero, $zero
/* DF86AC 80241CAC 12570004 */  beq       $s2, $s7, .L80241CC0
/* DF86B0 80241CB0 24620001 */   addiu    $v0, $v1, 1
/* DF86B4 80241CB4 16B70004 */  bne       $s5, $s7, .L80241CC8
/* DF86B8 80241CB8 328800FF */   andi     $t0, $s4, 0xff
/* DF86BC 80241CBC 24620001 */  addiu     $v0, $v1, 1
.L80241CC0:
/* DF86C0 80241CC0 AFA20044 */  sw        $v0, 0x44($sp)
.L80241CC4:
/* DF86C4 80241CC4 328800FF */  andi      $t0, $s4, 0xff
.L80241CC8:
/* DF86C8 80241CC8 32A7FFFF */  andi      $a3, $s5, 0xffff
/* DF86CC 80241CCC 00061080 */  sll       $v0, $a2, 2
/* DF86D0 80241CD0 00452021 */  addu      $a0, $v0, $a1
.L80241CD4:
/* DF86D4 80241CD4 90820000 */  lbu       $v0, ($a0)
/* DF86D8 80241CD8 55020009 */  bnel      $t0, $v0, .L80241D00
/* DF86DC 80241CDC 24840004 */   addiu    $a0, $a0, 4
/* DF86E0 80241CE0 90820001 */  lbu       $v0, 1($a0)
/* DF86E4 80241CE4 54E20006 */  bnel      $a3, $v0, .L80241D00
/* DF86E8 80241CE8 24840004 */   addiu    $a0, $a0, 4
/* DF86EC 80241CEC 84830002 */  lh        $v1, 2($a0)
/* DF86F0 80241CF0 8FA20044 */  lw        $v0, 0x44($sp)
/* DF86F4 80241CF4 00431021 */  addu      $v0, $v0, $v1
/* DF86F8 80241CF8 AFA20044 */  sw        $v0, 0x44($sp)
/* DF86FC 80241CFC 24840004 */  addiu     $a0, $a0, 4
.L80241D00:
/* DF8700 80241D00 84820002 */  lh        $v0, 2($a0)
/* DF8704 80241D04 1440FFF3 */  bnez      $v0, .L80241CD4
/* DF8708 80241D08 00000000 */   nop      
.L80241D0C:
/* DF870C 80241D0C 32C2FFFF */  andi      $v0, $s6, 0xffff
/* DF8710 80241D10 1040FFAC */  beqz      $v0, .L80241BC4
/* DF8714 80241D14 00000000 */   nop      
/* DF8718 80241D18 96620070 */  lhu       $v0, 0x70($s3)
/* DF871C 80241D1C 8FA30044 */  lw        $v1, 0x44($sp)
/* DF8720 80241D20 30420001 */  andi      $v0, $v0, 1
/* DF8724 80241D24 10400015 */  beqz      $v0, .L80241D7C
/* DF8728 80241D28 AE630014 */   sw       $v1, 0x14($s3)
/* DF872C 80241D2C 44831000 */  mtc1      $v1, $f2
/* DF8730 80241D30 00000000 */  nop       
/* DF8734 80241D34 468010A0 */  cvt.s.w   $f2, $f2
/* DF8738 80241D38 3C013FE0 */  lui       $at, 0x3fe0
/* DF873C 80241D3C 44810800 */  mtc1      $at, $f1
/* DF8740 80241D40 44800000 */  mtc1      $zero, $f0
/* DF8744 80241D44 460010A1 */  cvt.d.s   $f2, $f2
/* DF8748 80241D48 46201082 */  mul.d     $f2, $f2, $f0
/* DF874C 80241D4C 00000000 */  nop       
/* DF8750 80241D50 44800000 */  mtc1      $zero, $f0
/* DF8754 80241D54 44800800 */  mtc1      $zero, $f1
/* DF8758 80241D58 00000000 */  nop       
/* DF875C 80241D5C 46201080 */  add.d     $f2, $f2, $f0
/* DF8760 80241D60 C6600068 */  lwc1      $f0, 0x68($s3)
/* DF8764 80241D64 46800021 */  cvt.d.w   $f0, $f0
/* DF8768 80241D68 46220001 */  sub.d     $f0, $f0, $f2
/* DF876C 80241D6C 4620010D */  trunc.w.d $f4, $f0
/* DF8770 80241D70 44152000 */  mfc1      $s5, $f4
/* DF8774 80241D74 08090761 */  j         .L80241D84
/* DF8778 80241D78 0000B82D */   daddu    $s7, $zero, $zero
.L80241D7C:
/* DF877C 80241D7C 8E750068 */  lw        $s5, 0x68($s3)
/* DF8780 80241D80 0000B82D */  daddu     $s7, $zero, $zero
.L80241D84:
/* DF8784 80241D84 AE000004 */  sw        $zero, 4($s0)
/* DF8788 80241D88 AE000008 */  sw        $zero, 8($s0)
/* DF878C 80241D8C 8E620010 */  lw        $v0, 0x10($s3)
/* DF8790 80241D90 02E0882D */  daddu     $s1, $s7, $zero
/* DF8794 80241D94 AE02000C */  sw        $v0, 0xc($s0)
.L80241D98:
/* DF8798 80241D98 8E620000 */  lw        $v0, ($s3)
/* DF879C 80241D9C A7A00050 */  sh        $zero, 0x50($sp)
/* DF87A0 80241DA0 00511821 */  addu      $v1, $v0, $s1
/* DF87A4 80241DA4 26310001 */  addiu     $s1, $s1, 1
/* DF87A8 80241DA8 00511021 */  addu      $v0, $v0, $s1
/* DF87AC 80241DAC 90740000 */  lbu       $s4, ($v1)
/* DF87B0 80241DB0 90560000 */  lbu       $s6, ($v0)
/* DF87B4 80241DB4 2684FF10 */  addiu     $a0, $s4, -0xf0
/* DF87B8 80241DB8 2C830010 */  sltiu     $v1, $a0, 0x10
/* DF87BC 80241DBC 10600016 */  beqz      $v1, .L80241E18
/* DF87C0 80241DC0 00041080 */   sll      $v0, $a0, 2
/* DF87C4 80241DC4 3C018025 */  lui       $at, %hi(D_8024E900)
/* DF87C8 80241DC8 00220821 */  addu      $at, $at, $v0
/* DF87CC 80241DCC 8C22E900 */  lw        $v0, %lo(D_8024E900)($at)
/* DF87D0 80241DD0 00400008 */  jr        $v0
/* DF87D4 80241DD4 00000000 */   nop      
/* DF87D8 80241DD8 2682FF0D */  addiu     $v0, $s4, -0xf3
/* DF87DC 80241DDC 0809083B */  j         .L802420EC
/* DF87E0 80241DE0 AE020008 */   sw       $v0, 8($s0)
/* DF87E4 80241DE4 24090001 */  addiu     $t1, $zero, 1
/* DF87E8 80241DE8 0809083B */  j         .L802420EC
/* DF87EC 80241DEC A7A90050 */   sh       $t1, 0x50($sp)
/* DF87F0 80241DF0 8E630000 */  lw        $v1, ($s3)
/* DF87F4 80241DF4 00711021 */  addu      $v0, $v1, $s1
/* DF87F8 80241DF8 90420000 */  lbu       $v0, ($v0)
/* DF87FC 80241DFC 144000BB */  bnez      $v0, .L802420EC
/* DF8800 80241E00 26310001 */   addiu    $s1, $s1, 1
/* DF8804 80241E04 00711021 */  addu      $v0, $v1, $s1
/* DF8808 80241E08 90420000 */  lbu       $v0, ($v0)
/* DF880C 80241E0C 26310001 */  addiu     $s1, $s1, 1
/* DF8810 80241E10 0809083B */  j         .L802420EC
/* DF8814 80241E14 AE020004 */   sw       $v0, 4($s0)
.L80241E18:
/* DF8818 80241E18 328300FF */  andi      $v1, $s4, 0xff
/* DF881C 80241E1C 2C6200F0 */  sltiu     $v0, $v1, 0xf0
/* DF8820 80241E20 10400083 */  beqz      $v0, .L80242030
/* DF8824 80241E24 24090001 */   addiu    $t1, $zero, 1
/* DF8828 80241E28 AE030000 */  sw        $v1, ($s0)
/* DF882C 80241E2C AE150010 */  sw        $s5, 0x10($s0)
/* DF8830 80241E30 8E62006C */  lw        $v0, 0x6c($s3)
/* DF8834 80241E34 AE020014 */  sw        $v0, 0x14($s0)
/* DF8838 80241E38 8E63000C */  lw        $v1, 0xc($s3)
/* DF883C 80241E3C 1069003F */  beq       $v1, $t1, .L80241F3C
/* DF8840 80241E40 28620002 */   slti     $v0, $v1, 2
/* DF8844 80241E44 50400005 */  beql      $v0, $zero, .L80241E5C
/* DF8848 80241E48 24090002 */   addiu    $t1, $zero, 2
/* DF884C 80241E4C 10600007 */  beqz      $v1, .L80241E6C
/* DF8850 80241E50 00000000 */   nop      
/* DF8854 80241E54 0809080D */  j         .L80242034
/* DF8858 80241E58 26F70001 */   addiu    $s7, $s7, 1
.L80241E5C:
/* DF885C 80241E5C 10690043 */  beq       $v1, $t1, .L80241F6C
/* DF8860 80241E60 00000000 */   nop      
/* DF8864 80241E64 0809080C */  j         .L80242030
/* DF8868 80241E68 26F70001 */   addiu    $s7, $s7, 1
.L80241E6C:
/* DF886C 80241E6C 8E620020 */  lw        $v0, 0x20($s3)
/* DF8870 80241E70 00570018 */  mult      $v0, $s7
/* DF8874 80241E74 8E620008 */  lw        $v0, 8($s3)
/* DF8878 80241E78 00004812 */  mflo      $t1
/* DF887C 80241E7C 00491023 */  subu      $v0, $v0, $t1
/* DF8880 80241E80 0440006A */  bltz      $v0, .L8024202C
/* DF8884 80241E84 AE020018 */   sw       $v0, 0x18($s0)
/* DF8888 80241E88 8E63001C */  lw        $v1, 0x1c($s3)
/* DF888C 80241E8C 0062102A */  slt       $v0, $v1, $v0
/* DF8890 80241E90 54400001 */  bnel      $v0, $zero, .L80241E98
/* DF8894 80241E94 AE030018 */   sw       $v1, 0x18($s0)
.L80241E98:
/* DF8898 80241E98 240900FD */  addiu     $t1, $zero, 0xfd
/* DF889C 80241E9C 16C90005 */  bne       $s6, $t1, .L80241EB4
/* DF88A0 80241EA0 00000000 */   nop      
/* DF88A4 80241EA4 8E030018 */  lw        $v1, 0x18($s0)
/* DF88A8 80241EA8 8E62001C */  lw        $v0, 0x1c($s3)
/* DF88AC 80241EAC 50620001 */  beql      $v1, $v0, .L80241EB4
/* DF88B0 80241EB0 241E0001 */   addiu    $fp, $zero, 1
.L80241EB4:
/* DF88B4 80241EB4 8E630018 */  lw        $v1, 0x18($s3)
/* DF88B8 80241EB8 2C620006 */  sltiu     $v0, $v1, 6
/* DF88BC 80241EBC 1040005B */  beqz      $v0, .L8024202C
/* DF88C0 80241EC0 00031080 */   sll      $v0, $v1, 2
/* DF88C4 80241EC4 3C018025 */  lui       $at, %hi(D_8024E940)
/* DF88C8 80241EC8 00220821 */  addu      $at, $at, $v0
/* DF88CC 80241ECC 8C22E940 */  lw        $v0, %lo(D_8024E940)($at)
/* DF88D0 80241ED0 00400008 */  jr        $v0
/* DF88D4 80241ED4 00000000 */   nop      
/* DF88D8 80241ED8 0260202D */  daddu     $a0, $s3, $zero
/* DF88DC 80241EDC 0C09009C */  jal       func_80240270_DF6C70
/* DF88E0 80241EE0 0200282D */   daddu    $a1, $s0, $zero
/* DF88E4 80241EE4 0809080C */  j         .L80242030
/* DF88E8 80241EE8 26F70001 */   addiu    $s7, $s7, 1
/* DF88EC 80241EEC 0260202D */  daddu     $a0, $s3, $zero
/* DF88F0 80241EF0 0C090150 */  jal       func_80240540_DF6F40
/* DF88F4 80241EF4 0200282D */   daddu    $a1, $s0, $zero
/* DF88F8 80241EF8 0809080C */  j         .L80242030
/* DF88FC 80241EFC 26F70001 */   addiu    $s7, $s7, 1
/* DF8900 80241F00 0260202D */  daddu     $a0, $s3, $zero
/* DF8904 80241F04 0C090207 */  jal       func_8024081C_DF721C
/* DF8908 80241F08 0200282D */   daddu    $a1, $s0, $zero
/* DF890C 80241F0C 0809080C */  j         .L80242030
/* DF8910 80241F10 26F70001 */   addiu    $s7, $s7, 1
/* DF8914 80241F14 0260202D */  daddu     $a0, $s3, $zero
/* DF8918 80241F18 0C0902BA */  jal       func_80240AE8_DF74E8
/* DF891C 80241F1C 0200282D */   daddu    $a1, $s0, $zero
/* DF8920 80241F20 0809080C */  j         .L80242030
/* DF8924 80241F24 26F70001 */   addiu    $s7, $s7, 1
/* DF8928 80241F28 0260202D */  daddu     $a0, $s3, $zero
/* DF892C 80241F2C 0C0903AC */  jal       func_80240EB0_DF78B0
/* DF8930 80241F30 0200282D */   daddu    $a1, $s0, $zero
/* DF8934 80241F34 0809080C */  j         .L80242030
/* DF8938 80241F38 26F70001 */   addiu    $s7, $s7, 1
.L80241F3C:
/* DF893C 80241F3C 240900FD */  addiu     $t1, $zero, 0xfd
/* DF8940 80241F40 16C90006 */  bne       $s6, $t1, .L80241F5C
/* DF8944 80241F44 0260202D */   daddu    $a0, $s3, $zero
/* DF8948 80241F48 8E630008 */  lw        $v1, 8($s3)
/* DF894C 80241F4C 8E620038 */  lw        $v0, 0x38($s3)
/* DF8950 80241F50 50620002 */  beql      $v1, $v0, .L80241F5C
/* DF8954 80241F54 241E0001 */   addiu    $fp, $zero, 1
/* DF8958 80241F58 0260202D */  daddu     $a0, $s3, $zero
.L80241F5C:
/* DF895C 80241F5C 0C090473 */  jal       func_802411CC_DF7BCC
/* DF8960 80241F60 0200282D */   daddu    $a1, $s0, $zero
/* DF8964 80241F64 0809080C */  j         .L80242030
/* DF8968 80241F68 26F70001 */   addiu    $s7, $s7, 1
.L80241F6C:
/* DF896C 80241F6C 8E620054 */  lw        $v0, 0x54($s3)
/* DF8970 80241F70 00570018 */  mult      $v0, $s7
/* DF8974 80241F74 8E620008 */  lw        $v0, 8($s3)
/* DF8978 80241F78 00004812 */  mflo      $t1
/* DF897C 80241F7C 00491023 */  subu      $v0, $v0, $t1
/* DF8980 80241F80 04410002 */  bgez      $v0, .L80241F8C
/* DF8984 80241F84 AE020018 */   sw       $v0, 0x18($s0)
/* DF8988 80241F88 AE000018 */  sw        $zero, 0x18($s0)
.L80241F8C:
/* DF898C 80241F8C 8E020018 */  lw        $v0, 0x18($s0)
/* DF8990 80241F90 8E630050 */  lw        $v1, 0x50($s3)
/* DF8994 80241F94 0062102A */  slt       $v0, $v1, $v0
/* DF8998 80241F98 54400001 */  bnel      $v0, $zero, .L80241FA0
/* DF899C 80241F9C AE030018 */   sw       $v1, 0x18($s0)
.L80241FA0:
/* DF89A0 80241FA0 240900FD */  addiu     $t1, $zero, 0xfd
/* DF89A4 80241FA4 16C90005 */  bne       $s6, $t1, .L80241FBC
/* DF89A8 80241FA8 00000000 */   nop      
/* DF89AC 80241FAC 8E030018 */  lw        $v1, 0x18($s0)
/* DF89B0 80241FB0 8E620050 */  lw        $v0, 0x50($s3)
/* DF89B4 80241FB4 50620001 */  beql      $v1, $v0, .L80241FBC
/* DF89B8 80241FB8 241E0001 */   addiu    $fp, $zero, 1
.L80241FBC:
/* DF89BC 80241FBC 8E63004C */  lw        $v1, 0x4c($s3)
/* DF89C0 80241FC0 24090001 */  addiu     $t1, $zero, 1
/* DF89C4 80241FC4 1069000D */  beq       $v1, $t1, .L80241FFC
/* DF89C8 80241FC8 28620002 */   slti     $v0, $v1, 2
/* DF89CC 80241FCC 50400005 */  beql      $v0, $zero, .L80241FE4
/* DF89D0 80241FD0 24090002 */   addiu    $t1, $zero, 2
/* DF89D4 80241FD4 10600013 */  beqz      $v1, .L80242024
/* DF89D8 80241FD8 0260202D */   daddu    $a0, $s3, $zero
/* DF89DC 80241FDC 0809080D */  j         .L80242034
/* DF89E0 80241FE0 26F70001 */   addiu    $s7, $s7, 1
.L80241FE4:
/* DF89E4 80241FE4 1069000A */  beq       $v1, $t1, .L80242010
/* DF89E8 80241FE8 24020003 */   addiu    $v0, $zero, 3
/* DF89EC 80241FEC 1062000D */  beq       $v1, $v0, .L80242024
/* DF89F0 80241FF0 0260202D */   daddu    $a0, $s3, $zero
/* DF89F4 80241FF4 0809080C */  j         .L80242030
/* DF89F8 80241FF8 26F70001 */   addiu    $s7, $s7, 1
.L80241FFC:
/* DF89FC 80241FFC 0260202D */  daddu     $a0, $s3, $zero
/* DF8A00 80242000 0C090533 */  jal       func_802414CC_DF7ECC
/* DF8A04 80242004 0200282D */   daddu    $a1, $s0, $zero
/* DF8A08 80242008 0809080C */  j         .L80242030
/* DF8A0C 8024200C 26F70001 */   addiu    $s7, $s7, 1
.L80242010:
/* DF8A10 80242010 0260202D */  daddu     $a0, $s3, $zero
/* DF8A14 80242014 0C0905DA */  jal       func_80241768_DF8168
/* DF8A18 80242018 0200282D */   daddu    $a1, $s0, $zero
/* DF8A1C 8024201C 0809080C */  j         .L80242030
/* DF8A20 80242020 26F70001 */   addiu    $s7, $s7, 1
.L80242024:
/* DF8A24 80242024 0C09067E */  jal       func_802419F8_DF83F8
/* DF8A28 80242028 0200282D */   daddu    $a1, $s0, $zero
.L8024202C:
/* DF8A2C 8024202C 26F70001 */  addiu     $s7, $s7, 1
.L80242030:
/* DF8A30 80242030 24090001 */  addiu     $t1, $zero, 1
.L80242034:
/* DF8A34 80242034 329200FF */  andi      $s2, $s4, 0xff
/* DF8A38 80242038 AFA00010 */  sw        $zero, 0x10($sp)
/* DF8A3C 8024203C AFA90014 */  sw        $t1, 0x14($sp)
/* DF8A40 80242040 8E050004 */  lw        $a1, 4($s0)
/* DF8A44 80242044 8E060008 */  lw        $a2, 8($s0)
/* DF8A48 80242048 3C073F80 */  lui       $a3, 0x3f80
/* DF8A4C 8024204C 0C049721 */  jal       func_80125C84
/* DF8A50 80242050 0240202D */   daddu    $a0, $s2, $zero
/* DF8A54 80242054 26A3FFFF */  addiu     $v1, $s5, -1
/* DF8A58 80242058 8E040004 */  lw        $a0, 4($s0)
/* DF8A5C 8024205C 0062A821 */  addu      $s5, $v1, $v0
/* DF8A60 80242060 2482FFFD */  addiu     $v0, $a0, -3
/* DF8A64 80242064 2C420002 */  sltiu     $v0, $v0, 2
/* DF8A68 80242068 10400020 */  beqz      $v0, .L802420EC
/* DF8A6C 8024206C 00000000 */   nop      
/* DF8A70 80242070 3C058024 */  lui       $a1, %hi(D_80242CD8)
/* DF8A74 80242074 24A52CD8 */  addiu     $a1, $a1, %lo(D_80242CD8)
/* DF8A78 80242078 24090004 */  addiu     $t1, $zero, 4
/* DF8A7C 8024207C 14890003 */  bne       $a0, $t1, .L8024208C
/* DF8A80 80242080 00000000 */   nop      
/* DF8A84 80242084 3C058024 */  lui       $a1, %hi(D_80242C70)
/* DF8A88 80242088 24A52C70 */  addiu     $a1, $a1, %lo(D_80242C70)
.L8024208C:
/* DF8A8C 8024208C 14890007 */  bne       $a0, $t1, .L802420AC
/* DF8A90 80242090 0000302D */   daddu    $a2, $zero, $zero
/* DF8A94 80242094 24020008 */  addiu     $v0, $zero, 8
/* DF8A98 80242098 52420004 */  beql      $s2, $v0, .L802420AC
/* DF8A9C 8024209C 26B50001 */   addiu    $s5, $s5, 1
/* DF8AA0 802420A0 16C20003 */  bne       $s6, $v0, .L802420B0
/* DF8AA4 802420A4 328300FF */   andi     $v1, $s4, 0xff
/* DF8AA8 802420A8 26B50001 */  addiu     $s5, $s5, 1
.L802420AC:
/* DF8AAC 802420AC 328300FF */  andi      $v1, $s4, 0xff
.L802420B0:
/* DF8AB0 802420B0 32C7FFFF */  andi      $a3, $s6, 0xffff
/* DF8AB4 802420B4 00061080 */  sll       $v0, $a2, 2
/* DF8AB8 802420B8 00452021 */  addu      $a0, $v0, $a1
.L802420BC:
/* DF8ABC 802420BC 90820000 */  lbu       $v0, ($a0)
/* DF8AC0 802420C0 54620007 */  bnel      $v1, $v0, .L802420E0
/* DF8AC4 802420C4 24840004 */   addiu    $a0, $a0, 4
/* DF8AC8 802420C8 90820001 */  lbu       $v0, 1($a0)
/* DF8ACC 802420CC 54E20004 */  bnel      $a3, $v0, .L802420E0
/* DF8AD0 802420D0 24840004 */   addiu    $a0, $a0, 4
/* DF8AD4 802420D4 84820002 */  lh        $v0, 2($a0)
/* DF8AD8 802420D8 02A2A821 */  addu      $s5, $s5, $v0
/* DF8ADC 802420DC 24840004 */  addiu     $a0, $a0, 4
.L802420E0:
/* DF8AE0 802420E0 84820002 */  lh        $v0, 2($a0)
/* DF8AE4 802420E4 1440FFF5 */  bnez      $v0, .L802420BC
/* DF8AE8 802420E8 00000000 */   nop      
.L802420EC:
/* DF8AEC 802420EC 97A20050 */  lhu       $v0, 0x50($sp)
/* DF8AF0 802420F0 1040FF29 */  beqz      $v0, .L80241D98
/* DF8AF4 802420F4 00000000 */   nop      
/* DF8AF8 802420F8 8E62000C */  lw        $v0, 0xc($s3)
/* DF8AFC 802420FC 14400015 */  bnez      $v0, .L80242154
/* DF8B00 80242100 00000000 */   nop      
/* DF8B04 80242104 13C00013 */  beqz      $fp, .L80242154
/* DF8B08 80242108 0000282D */   daddu    $a1, $zero, $zero
/* DF8B0C 8024210C 00A0302D */  daddu     $a2, $a1, $zero
/* DF8B10 80242110 AFA0004C */  sw        $zero, 0x4c($sp)
/* DF8B14 80242114 AFA00010 */  sw        $zero, 0x10($sp)
/* DF8B18 80242118 AFA00014 */  sw        $zero, 0x14($sp)
/* DF8B1C 8024211C AFA00018 */  sw        $zero, 0x18($sp)
/* DF8B20 80242120 AFA0001C */  sw        $zero, 0x1c($sp)
/* DF8B24 80242124 8E640000 */  lw        $a0, ($s3)
/* DF8B28 80242128 0C0497DA */  jal       get_string_properties
/* DF8B2C 8024212C 27A7004C */   addiu    $a3, $sp, 0x4c
/* DF8B30 80242130 8E64000C */  lw        $a0, 0xc($s3)
/* DF8B34 80242134 8E630038 */  lw        $v1, 0x38($s3)
/* DF8B38 80242138 AE600008 */  sw        $zero, 8($s3)
/* DF8B3C 8024213C 24820001 */  addiu     $v0, $a0, 1
/* DF8B40 80242140 1C600016 */  bgtz      $v1, .L8024219C
/* DF8B44 80242144 AE62000C */   sw       $v0, 0xc($s3)
/* DF8B48 80242148 24820002 */  addiu     $v0, $a0, 2
/* DF8B4C 8024214C 08090867 */  j         .L8024219C
/* DF8B50 80242150 AE62000C */   sw       $v0, 0xc($s3)
.L80242154:
/* DF8B54 80242154 8E63000C */  lw        $v1, 0xc($s3)
/* DF8B58 80242158 24020001 */  addiu     $v0, $zero, 1
/* DF8B5C 8024215C 14620008 */  bne       $v1, $v0, .L80242180
/* DF8B60 80242160 24020002 */   addiu    $v0, $zero, 2
/* DF8B64 80242164 13C00005 */  beqz      $fp, .L8024217C
/* DF8B68 80242168 0060102D */   daddu    $v0, $v1, $zero
/* DF8B6C 8024216C 24420001 */  addiu     $v0, $v0, 1
/* DF8B70 80242170 AE600008 */  sw        $zero, 8($s3)
/* DF8B74 80242174 08090867 */  j         .L8024219C
/* DF8B78 80242178 AE62000C */   sw       $v0, 0xc($s3)
.L8024217C:
/* DF8B7C 8024217C 24020002 */  addiu     $v0, $zero, 2
.L80242180:
/* DF8B80 80242180 14620006 */  bne       $v1, $v0, .L8024219C
/* DF8B84 80242184 00000000 */   nop      
/* DF8B88 80242188 13C00004 */  beqz      $fp, .L8024219C
/* DF8B8C 8024218C 00000000 */   nop      
/* DF8B90 80242190 96620070 */  lhu       $v0, 0x70($s3)
/* DF8B94 80242194 3042FFFE */  andi      $v0, $v0, 0xfffe
/* DF8B98 80242198 A6620070 */  sh        $v0, 0x70($s3)
.L8024219C:
/* DF8B9C 8024219C 8E620008 */  lw        $v0, 8($s3)
/* DF8BA0 802421A0 24420001 */  addiu     $v0, $v0, 1
/* DF8BA4 802421A4 AE620008 */  sw        $v0, 8($s3)
/* DF8BA8 802421A8 8FBF007C */  lw        $ra, 0x7c($sp)
/* DF8BAC 802421AC 8FBE0078 */  lw        $fp, 0x78($sp)
/* DF8BB0 802421B0 8FB70074 */  lw        $s7, 0x74($sp)
/* DF8BB4 802421B4 8FB60070 */  lw        $s6, 0x70($sp)
/* DF8BB8 802421B8 8FB5006C */  lw        $s5, 0x6c($sp)
/* DF8BBC 802421BC 8FB40068 */  lw        $s4, 0x68($sp)
/* DF8BC0 802421C0 8FB30064 */  lw        $s3, 0x64($sp)
/* DF8BC4 802421C4 8FB20060 */  lw        $s2, 0x60($sp)
/* DF8BC8 802421C8 8FB1005C */  lw        $s1, 0x5c($sp)
/* DF8BCC 802421CC 8FB00058 */  lw        $s0, 0x58($sp)
/* DF8BD0 802421D0 03E00008 */  jr        $ra
/* DF8BD4 802421D4 27BD0080 */   addiu    $sp, $sp, 0x80
