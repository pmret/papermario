.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80147698
/* DDD98 80147698 27BDFF10 */  addiu     $sp, $sp, -0xf0
/* DDD9C 8014769C AFB700DC */  sw        $s7, 0xdc($sp)
/* DDDA0 801476A0 00A0B82D */  daddu     $s7, $a1, $zero
/* DDDA4 801476A4 AFB600D8 */  sw        $s6, 0xd8($sp)
/* DDDA8 801476A8 0000B02D */  daddu     $s6, $zero, $zero
/* DDDAC 801476AC AFB300CC */  sw        $s3, 0xcc($sp)
/* DDDB0 801476B0 AFA400F0 */  sw        $a0, 0xf0($sp)
/* DDDB4 801476B4 0080982D */  daddu     $s3, $a0, $zero
/* DDDB8 801476B8 00171140 */  sll       $v0, $s7, 5
/* DDDBC 801476BC F7B400E8 */  sdc1      $f20, 0xe8($sp)
/* DDDC0 801476C0 4480A000 */  mtc1      $zero, $f20
/* DDDC4 801476C4 3C0B8016 */  lui       $t3, %hi(gUIPanels)
/* DDDC8 801476C8 256B9D50 */  addiu     $t3, $t3, %lo(gUIPanels)
/* DDDCC 801476CC AFBE00E0 */  sw        $fp, 0xe0($sp)
/* DDDD0 801476D0 004BF021 */  addu      $fp, $v0, $t3
/* DDDD4 801476D4 AFBF00E4 */  sw        $ra, 0xe4($sp)
/* DDDD8 801476D8 AFB500D4 */  sw        $s5, 0xd4($sp)
/* DDDDC 801476DC AFB400D0 */  sw        $s4, 0xd0($sp)
/* DDDE0 801476E0 AFB200C8 */  sw        $s2, 0xc8($sp)
/* DDDE4 801476E4 AFB100C4 */  sw        $s1, 0xc4($sp)
/* DDDE8 801476E8 AFB000C0 */  sw        $s0, 0xc0($sp)
/* DDDEC 801476EC AFA600F8 */  sw        $a2, 0xf8($sp)
/* DDDF0 801476F0 AFA700FC */  sw        $a3, 0xfc($sp)
.L801476F4:
/* DDDF4 801476F4 8E720000 */  lw        $s2, ($s3)
/* DDDF8 801476F8 064200E2 */  bltzl     $s2, .L80147A84
/* DDDFC 801476FC 26D60001 */   addiu    $s6, $s6, 1
/* DDE00 80147700 00121140 */  sll       $v0, $s2, 5
/* DDE04 80147704 3C0B8016 */  lui       $t3, %hi(gUIPanels)
/* DDE08 80147708 256B9D50 */  addiu     $t3, $t3, %lo(gUIPanels)
/* DDE0C 8014770C 004B8821 */  addu      $s1, $v0, $t3
/* DDE10 80147710 92220000 */  lbu       $v0, ($s1)
/* DDE14 80147714 504000DB */  beql      $v0, $zero, .L80147A84
/* DDE18 80147718 26D60001 */   addiu    $s6, $s6, 1
/* DDE1C 8014771C 30420020 */  andi      $v0, $v0, 0x20
/* DDE20 80147720 544000D8 */  bnel      $v0, $zero, .L80147A84
/* DDE24 80147724 26D60001 */   addiu    $s6, $s6, 1
/* DDE28 80147728 8E250004 */  lw        $a1, 4($s1)
/* DDE2C 8014772C 50A000D5 */  beql      $a1, $zero, .L80147A84
/* DDE30 80147730 26D60001 */   addiu    $s6, $s6, 1
/* DDE34 80147734 82220003 */  lb        $v0, 3($s1)
/* DDE38 80147738 545700D2 */  bnel      $v0, $s7, .L80147A84
/* DDE3C 8014773C 26D60001 */   addiu    $s6, $s6, 1
/* DDE40 80147740 9226001C */  lbu       $a2, 0x1c($s1)
/* DDE44 80147744 AFA0009C */  sw        $zero, 0x9c($sp)
/* DDE48 80147748 AFA00090 */  sw        $zero, 0x90($sp)
/* DDE4C 8014774C E7B400B0 */  swc1      $f20, 0xb0($sp)
/* DDE50 80147750 E7B400AC */  swc1      $f20, 0xac($sp)
/* DDE54 80147754 E7B400A8 */  swc1      $f20, 0xa8($sp)
/* DDE58 80147758 AFA000B4 */  sw        $zero, 0xb4($sp)
/* DDE5C 8014775C 8623000C */  lh        $v1, 0xc($s1)
/* DDE60 80147760 8624000E */  lh        $a0, 0xe($s1)
/* DDE64 80147764 240200FF */  addiu     $v0, $zero, 0xff
/* DDE68 80147768 AFA200B8 */  sw        $v0, 0xb8($sp)
/* DDE6C 8014776C 24A2FFFF */  addiu     $v0, $a1, -1
/* DDE70 80147770 3C013F80 */  lui       $at, 0x3f80
/* DDE74 80147774 44810000 */  mtc1      $at, $f0
/* DDE78 80147778 2C42000D */  sltiu     $v0, $v0, 0xd
/* DDE7C 8014777C AFA30094 */  sw        $v1, 0x94($sp)
/* DDE80 80147780 AFA40098 */  sw        $a0, 0x98($sp)
/* DDE84 80147784 E7A000A0 */  swc1      $f0, 0xa0($sp)
/* DDE88 80147788 E7A000A4 */  swc1      $f0, 0xa4($sp)
/* DDE8C 8014778C 86340010 */  lh        $s4, 0x10($s1)
/* DDE90 80147790 86350012 */  lh        $s5, 0x12($s1)
/* DDE94 80147794 10400022 */  beqz      $v0, .L80147820
/* DDE98 80147798 00051080 */   sll      $v0, $a1, 2
/* DDE9C 8014779C 3C038015 */  lui       $v1, %hi(D_8014F250)
/* DDEA0 801477A0 2463F250 */  addiu     $v1, $v1, %lo(D_8014F250)
/* DDEA4 801477A4 00451021 */  addu      $v0, $v0, $a1
/* DDEA8 801477A8 00438021 */  addu      $s0, $v0, $v1
/* DDEAC 801477AC 92230000 */  lbu       $v1, ($s1)
/* DDEB0 801477B0 92020001 */  lbu       $v0, 1($s0)
/* DDEB4 801477B4 00621825 */  or        $v1, $v1, $v0
/* DDEB8 801477B8 A2230000 */  sb        $v1, ($s1)
/* DDEBC 801477BC 92020002 */  lbu       $v0, 2($s0)
/* DDEC0 801477C0 00021027 */  nor       $v0, $zero, $v0
/* DDEC4 801477C4 00621824 */  and       $v1, $v1, $v0
/* DDEC8 801477C8 14C00008 */  bnez      $a2, .L801477EC
/* DDECC 801477CC A2230000 */   sb       $v1, ($s1)
/* DDED0 801477D0 92020000 */  lbu       $v0, ($s0)
/* DDED4 801477D4 30420001 */  andi      $v0, $v0, 1
/* DDED8 801477D8 10400004 */  beqz      $v0, .L801477EC
/* DDEDC 801477DC 00000000 */   nop
/* DDEE0 801477E0 92250002 */  lbu       $a1, 2($s1)
/* DDEE4 801477E4 0C051F5C */  jal       func_80147D70
/* DDEE8 801477E8 0240202D */   daddu    $a0, $s2, $zero
.L801477EC:
/* DDEEC 801477EC 92020000 */  lbu       $v0, ($s0)
/* DDEF0 801477F0 30420004 */  andi      $v0, $v0, 4
/* DDEF4 801477F4 10400003 */  beqz      $v0, .L80147804
/* DDEF8 801477F8 00000000 */   nop
/* DDEFC 801477FC 92020003 */  lbu       $v0, 3($s0)
/* DDF00 80147800 AFA200B4 */  sw        $v0, 0xb4($sp)
.L80147804:
/* DDF04 80147804 92020000 */  lbu       $v0, ($s0)
/* DDF08 80147808 30420002 */  andi      $v0, $v0, 2
/* DDF0C 8014780C 1040001A */  beqz      $v0, .L80147878
/* DDF10 80147810 00000000 */   nop
/* DDF14 80147814 92020004 */  lbu       $v0, 4($s0)
/* DDF18 80147818 08051E1E */  j         .L80147878
/* DDF1C 8014781C AFA200B8 */   sw       $v0, 0xb8($sp)
.L80147820:
/* DDF20 80147820 0240202D */  daddu     $a0, $s2, $zero
/* DDF24 80147824 27A50090 */  addiu     $a1, $sp, 0x90
/* DDF28 80147828 27A60094 */  addiu     $a2, $sp, 0x94
/* DDF2C 8014782C 27A70098 */  addiu     $a3, $sp, 0x98
/* DDF30 80147830 8E220004 */  lw        $v0, 4($s1)
/* DDF34 80147834 27A3009C */  addiu     $v1, $sp, 0x9c
/* DDF38 80147838 AFA30010 */  sw        $v1, 0x10($sp)
/* DDF3C 8014783C 27A300A0 */  addiu     $v1, $sp, 0xa0
/* DDF40 80147840 AFA30014 */  sw        $v1, 0x14($sp)
/* DDF44 80147844 27A300A4 */  addiu     $v1, $sp, 0xa4
/* DDF48 80147848 AFA30018 */  sw        $v1, 0x18($sp)
/* DDF4C 8014784C 27A300A8 */  addiu     $v1, $sp, 0xa8
/* DDF50 80147850 AFA3001C */  sw        $v1, 0x1c($sp)
/* DDF54 80147854 27A300AC */  addiu     $v1, $sp, 0xac
/* DDF58 80147858 AFA30020 */  sw        $v1, 0x20($sp)
/* DDF5C 8014785C 27A300B0 */  addiu     $v1, $sp, 0xb0
/* DDF60 80147860 AFA30024 */  sw        $v1, 0x24($sp)
/* DDF64 80147864 27A300B4 */  addiu     $v1, $sp, 0xb4
/* DDF68 80147868 AFA30028 */  sw        $v1, 0x28($sp)
/* DDF6C 8014786C 27A300B8 */  addiu     $v1, $sp, 0xb8
/* DDF70 80147870 0040F809 */  jalr      $v0
/* DDF74 80147874 AFA3002C */   sw       $v1, 0x2c($sp)
.L80147878:
/* DDF78 80147878 8E220004 */  lw        $v0, 4($s1)
/* DDF7C 8014787C 10400006 */  beqz      $v0, .L80147898
/* DDF80 80147880 00000000 */   nop
/* DDF84 80147884 9223001C */  lbu       $v1, 0x1c($s1)
/* DDF88 80147888 2C6200FF */  sltiu     $v0, $v1, 0xff
/* DDF8C 8014788C 10400002 */  beqz      $v0, .L80147898
/* DDF90 80147890 24620001 */   addiu    $v0, $v1, 1
/* DDF94 80147894 A222001C */  sb        $v0, 0x1c($s1)
.L80147898:
/* DDF98 80147898 C7A000A0 */  lwc1      $f0, 0xa0($sp)
/* DDF9C 8014789C 46140032 */  c.eq.s    $f0, $f20
/* DDFA0 801478A0 00000000 */  nop
/* DDFA4 801478A4 45030077 */  bc1tl     .L80147A84
/* DDFA8 801478A8 26D60001 */   addiu    $s6, $s6, 1
/* DDFAC 801478AC C7A000A4 */  lwc1      $f0, 0xa4($sp)
/* DDFB0 801478B0 46140032 */  c.eq.s    $f0, $f20
/* DDFB4 801478B4 00000000 */  nop
/* DDFB8 801478B8 45030072 */  bc1tl     .L80147A84
/* DDFBC 801478BC 26D60001 */   addiu    $s6, $s6, 1
/* DDFC0 801478C0 92220000 */  lbu       $v0, ($s1)
/* DDFC4 801478C4 30420004 */  andi      $v0, $v0, 4
/* DDFC8 801478C8 5440006E */  bnel      $v0, $zero, .L80147A84
/* DDFCC 801478CC 26D60001 */   addiu    $s6, $s6, 1
/* DDFD0 801478D0 8FA300B8 */  lw        $v1, 0xb8($sp)
/* DDFD4 801478D4 8FAB0104 */  lw        $t3, 0x104($sp)
/* DDFD8 801478D8 006B0018 */  mult      $v1, $t3
/* DDFDC 801478DC 3C028080 */  lui       $v0, 0x8080
/* DDFE0 801478E0 34428081 */  ori       $v0, $v0, 0x8081
/* DDFE4 801478E4 00001812 */  mflo      $v1
/* DDFE8 801478E8 8FA400B4 */  lw        $a0, 0xb4($sp)
/* DDFEC 801478EC 8FAB0108 */  lw        $t3, 0x108($sp)
/* DDFF0 801478F0 00620018 */  mult      $v1, $v0
/* DDFF4 801478F4 008B2021 */  addu      $a0, $a0, $t3
/* DDFF8 801478F8 AFA400B4 */  sw        $a0, 0xb4($sp)
/* DDFFC 801478FC 28840100 */  slti      $a0, $a0, 0x100
/* DE000 80147900 00004010 */  mfhi      $t0
/* DE004 80147904 01031021 */  addu      $v0, $t0, $v1
/* DE008 80147908 000211C3 */  sra       $v0, $v0, 7
/* DE00C 8014790C 00031FC3 */  sra       $v1, $v1, 0x1f
/* DE010 80147910 00431023 */  subu      $v0, $v0, $v1
/* DE014 80147914 AFA200B8 */  sw        $v0, 0xb8($sp)
/* DE018 80147918 00121080 */  sll       $v0, $s2, 2
/* DE01C 8014791C 8E290014 */  lw        $t1, 0x14($s1)
/* DE020 80147920 8E2A0018 */  lw        $t2, 0x18($s1)
/* DE024 80147924 3C058015 */  lui       $a1, %hi(D_8014F150)
/* DE028 80147928 00A22821 */  addu      $a1, $a1, $v0
/* DE02C 8014792C 8CA5F150 */  lw        $a1, %lo(D_8014F150)($a1)
/* DE030 80147930 14800003 */  bnez      $a0, .L80147940
/* DE034 80147934 27B00050 */   addiu    $s0, $sp, 0x50
/* DE038 80147938 240200FF */  addiu     $v0, $zero, 0xff
/* DE03C 8014793C AFA200B4 */  sw        $v0, 0xb4($sp)
.L80147940:
/* DE040 80147940 8FA20090 */  lw        $v0, 0x90($sp)
/* DE044 80147944 8FAB00F8 */  lw        $t3, 0xf8($sp)
/* DE048 80147948 004B1025 */  or        $v0, $v0, $t3
/* DE04C 8014794C AFA20090 */  sw        $v0, 0x90($sp)
/* DE050 80147950 31620001 */  andi      $v0, $t3, 1
/* DE054 80147954 1440000A */  bnez      $v0, .L80147980
/* DE058 80147958 2402FFFF */   addiu    $v0, $zero, -1
/* DE05C 8014795C 8FA20094 */  lw        $v0, 0x94($sp)
/* DE060 80147960 8FAB00FC */  lw        $t3, 0xfc($sp)
/* DE064 80147964 8FA30098 */  lw        $v1, 0x98($sp)
/* DE068 80147968 004B1021 */  addu      $v0, $v0, $t3
/* DE06C 8014796C 8FAB0100 */  lw        $t3, 0x100($sp)
/* DE070 80147970 AFA20094 */  sw        $v0, 0x94($sp)
/* DE074 80147974 006B1821 */  addu      $v1, $v1, $t3
/* DE078 80147978 AFA30098 */  sw        $v1, 0x98($sp)
/* DE07C 8014797C 2402FFFF */  addiu     $v0, $zero, -1
.L80147980:
/* DE080 80147980 12E20002 */  beq       $s7, $v0, .L8014798C
/* DE084 80147984 24080140 */   addiu    $t0, $zero, 0x140
/* DE088 80147988 87C80010 */  lh        $t0, 0x10($fp)
.L8014798C:
/* DE08C 8014798C 2402FFFF */  addiu     $v0, $zero, -1
/* DE090 80147990 12E20002 */  beq       $s7, $v0, .L8014799C
/* DE094 80147994 240300F0 */   addiu    $v1, $zero, 0xf0
/* DE098 80147998 87C30012 */  lh        $v1, 0x12($fp)
.L8014799C:
/* DE09C 8014799C 92220000 */  lbu       $v0, ($s1)
/* DE0A0 801479A0 8FA40090 */  lw        $a0, 0x90($sp)
/* DE0A4 801479A4 30420040 */  andi      $v0, $v0, 0x40
/* DE0A8 801479A8 54400001 */  bnel      $v0, $zero, .L801479B0
/* DE0AC 801479AC 34840002 */   ori      $a0, $a0, 2
.L801479B0:
/* DE0B0 801479B0 8FA60094 */  lw        $a2, 0x94($sp)
/* DE0B4 801479B4 8FA70098 */  lw        $a3, 0x98($sp)
/* DE0B8 801479B8 8FA2009C */  lw        $v0, 0x9c($sp)
/* DE0BC 801479BC 8FAB010C */  lw        $t3, 0x10c($sp)
/* DE0C0 801479C0 AFB40014 */  sw        $s4, 0x14($sp)
/* DE0C4 801479C4 AFB50018 */  sw        $s5, 0x18($sp)
/* DE0C8 801479C8 AFA20010 */  sw        $v0, 0x10($sp)
/* DE0CC 801479CC 93A200BB */  lbu       $v0, 0xbb($sp)
/* DE0D0 801479D0 AFA2001C */  sw        $v0, 0x1c($sp)
/* DE0D4 801479D4 93A200B7 */  lbu       $v0, 0xb7($sp)
/* DE0D8 801479D8 AFA20020 */  sw        $v0, 0x20($sp)
/* DE0DC 801479DC C7A000A0 */  lwc1      $f0, 0xa0($sp)
/* DE0E0 801479E0 E7A00024 */  swc1      $f0, 0x24($sp)
/* DE0E4 801479E4 C7A000A4 */  lwc1      $f0, 0xa4($sp)
/* DE0E8 801479E8 E7A00028 */  swc1      $f0, 0x28($sp)
/* DE0EC 801479EC C7A000A8 */  lwc1      $f0, 0xa8($sp)
/* DE0F0 801479F0 E7A0002C */  swc1      $f0, 0x2c($sp)
/* DE0F4 801479F4 C7A000AC */  lwc1      $f0, 0xac($sp)
/* DE0F8 801479F8 E7A00030 */  swc1      $f0, 0x30($sp)
/* DE0FC 801479FC C7A000B0 */  lwc1      $f0, 0xb0($sp)
/* DE100 80147A00 AFA90038 */  sw        $t1, 0x38($sp)
/* DE104 80147A04 AFAA003C */  sw        $t2, 0x3c($sp)
/* DE108 80147A08 AFAB0040 */  sw        $t3, 0x40($sp)
/* DE10C 80147A0C AFA80044 */  sw        $t0, 0x44($sp)
/* DE110 80147A10 AFA30048 */  sw        $v1, 0x48($sp)
/* DE114 80147A14 AFB0004C */  sw        $s0, 0x4c($sp)
/* DE118 80147A18 0C03D4B8 */  jal       draw_box
/* DE11C 80147A1C E7A00034 */   swc1     $f0, 0x34($sp)
/* DE120 80147A20 54400018 */  bnel      $v0, $zero, .L80147A84
/* DE124 80147A24 26D60001 */   addiu    $s6, $s6, 1
/* DE128 80147A28 8FA20090 */  lw        $v0, 0x90($sp)
/* DE12C 80147A2C 14400004 */  bnez      $v0, .L80147A40
/* DE130 80147A30 00000000 */   nop
/* DE134 80147A34 8FAB010C */  lw        $t3, 0x10c($sp)
/* DE138 80147A38 51600001 */  beql      $t3, $zero, .L80147A40
/* DE13C 80147A3C 0000802D */   daddu    $s0, $zero, $zero
.L80147A40:
/* DE140 80147A40 92220000 */  lbu       $v0, ($s1)
/* DE144 80147A44 30420010 */  andi      $v0, $v0, 0x10
/* DE148 80147A48 5040000E */  beql      $v0, $zero, .L80147A84
/* DE14C 80147A4C 26D60001 */   addiu    $s6, $s6, 1
/* DE150 80147A50 8FA20098 */  lw        $v0, 0x98($sp)
/* DE154 80147A54 8FA400F0 */  lw        $a0, 0xf0($sp)
/* DE158 80147A58 8FA60090 */  lw        $a2, 0x90($sp)
/* DE15C 80147A5C 8FA70094 */  lw        $a3, 0x94($sp)
/* DE160 80147A60 AFA20010 */  sw        $v0, 0x10($sp)
/* DE164 80147A64 8FA200B8 */  lw        $v0, 0xb8($sp)
/* DE168 80147A68 AFA20014 */  sw        $v0, 0x14($sp)
/* DE16C 80147A6C 8FA200B4 */  lw        $v0, 0xb4($sp)
/* DE170 80147A70 0240282D */  daddu     $a1, $s2, $zero
/* DE174 80147A74 AFB0001C */  sw        $s0, 0x1c($sp)
/* DE178 80147A78 0C051DA6 */  jal       func_80147698
/* DE17C 80147A7C AFA20018 */   sw       $v0, 0x18($sp)
/* DE180 80147A80 26D60001 */  addiu     $s6, $s6, 1
.L80147A84:
/* DE184 80147A84 2AC20040 */  slti      $v0, $s6, 0x40
/* DE188 80147A88 1440FF1A */  bnez      $v0, .L801476F4
/* DE18C 80147A8C 26730004 */   addiu    $s3, $s3, 4
/* DE190 80147A90 8FBF00E4 */  lw        $ra, 0xe4($sp)
/* DE194 80147A94 8FBE00E0 */  lw        $fp, 0xe0($sp)
/* DE198 80147A98 8FB700DC */  lw        $s7, 0xdc($sp)
/* DE19C 80147A9C 8FB600D8 */  lw        $s6, 0xd8($sp)
/* DE1A0 80147AA0 8FB500D4 */  lw        $s5, 0xd4($sp)
/* DE1A4 80147AA4 8FB400D0 */  lw        $s4, 0xd0($sp)
/* DE1A8 80147AA8 8FB300CC */  lw        $s3, 0xcc($sp)
/* DE1AC 80147AAC 8FB200C8 */  lw        $s2, 0xc8($sp)
/* DE1B0 80147AB0 8FB100C4 */  lw        $s1, 0xc4($sp)
/* DE1B4 80147AB4 8FB000C0 */  lw        $s0, 0xc0($sp)
/* DE1B8 80147AB8 D7B400E8 */  ldc1      $f20, 0xe8($sp)
/* DE1BC 80147ABC 03E00008 */  jr        $ra
/* DE1C0 80147AC0 27BD00F0 */   addiu    $sp, $sp, 0xf0
