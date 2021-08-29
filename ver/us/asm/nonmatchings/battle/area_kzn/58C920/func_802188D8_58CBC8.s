.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802188D8_58CBC8
/* 58CBC8 802188D8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 58CBCC 802188DC AFB10014 */  sw        $s1, 0x14($sp)
/* 58CBD0 802188E0 0080882D */  daddu     $s1, $a0, $zero
/* 58CBD4 802188E4 AFBF0018 */  sw        $ra, 0x18($sp)
/* 58CBD8 802188E8 AFB00010 */  sw        $s0, 0x10($sp)
/* 58CBDC 802188EC 8E30000C */  lw        $s0, 0xc($s1)
/* 58CBE0 802188F0 8E050000 */  lw        $a1, ($s0)
/* 58CBE4 802188F4 0C0B1EAF */  jal       get_variable
/* 58CBE8 802188F8 26100004 */   addiu    $s0, $s0, 4
/* 58CBEC 802188FC 0040202D */  daddu     $a0, $v0, $zero
/* 58CBF0 80218900 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 58CBF4 80218904 14820002 */  bne       $a0, $v0, .L80218910
/* 58CBF8 80218908 00000000 */   nop
/* 58CBFC 8021890C 8E240148 */  lw        $a0, 0x148($s1)
.L80218910:
/* 58CC00 80218910 0C09A75B */  jal       get_actor
/* 58CC04 80218914 00000000 */   nop
/* 58CC08 80218918 0040202D */  daddu     $a0, $v0, $zero
/* 58CC0C 8021891C 90830136 */  lbu       $v1, 0x136($a0)
/* 58CC10 80218920 24020047 */  addiu     $v0, $zero, 0x47
/* 58CC14 80218924 1062000B */  beq       $v1, $v0, .L80218954
/* 58CC18 80218928 0062102A */   slt      $v0, $v1, $v0
/* 58CC1C 8021892C 54400011 */  bnel      $v0, $zero, .L80218974
/* 58CC20 80218930 0220202D */   daddu    $a0, $s1, $zero
/* 58CC24 80218934 28620065 */  slti      $v0, $v1, 0x65
/* 58CC28 80218938 1040000D */  beqz      $v0, .L80218970
/* 58CC2C 8021893C 2862004D */   slti     $v0, $v1, 0x4d
/* 58CC30 80218940 1440000C */  bnez      $v0, .L80218974
/* 58CC34 80218944 0220202D */   daddu    $a0, $s1, $zero
/* 58CC38 80218948 8E050000 */  lw        $a1, ($s0)
/* 58CC3C 8021894C 0808625F */  j         .L8021897C
/* 58CC40 80218950 2406FFFF */   addiu    $a2, $zero, -1
.L80218954:
/* 58CC44 80218954 8C8300A8 */  lw        $v1, 0xa8($a0)
/* 58CC48 80218958 24020001 */  addiu     $v0, $zero, 1
/* 58CC4C 8021895C 14620005 */  bne       $v1, $v0, .L80218974
/* 58CC50 80218960 0220202D */   daddu    $a0, $s1, $zero
/* 58CC54 80218964 8E050000 */  lw        $a1, ($s0)
/* 58CC58 80218968 0808625F */  j         .L8021897C
/* 58CC5C 8021896C 2406FFFF */   addiu    $a2, $zero, -1
.L80218970:
/* 58CC60 80218970 0220202D */  daddu     $a0, $s1, $zero
.L80218974:
/* 58CC64 80218974 8E050000 */  lw        $a1, ($s0)
/* 58CC68 80218978 0000302D */  daddu     $a2, $zero, $zero
.L8021897C:
/* 58CC6C 8021897C 0C0B2026 */  jal       evt_set_variable
/* 58CC70 80218980 00000000 */   nop
/* 58CC74 80218984 8FBF0018 */  lw        $ra, 0x18($sp)
/* 58CC78 80218988 8FB10014 */  lw        $s1, 0x14($sp)
/* 58CC7C 8021898C 8FB00010 */  lw        $s0, 0x10($sp)
/* 58CC80 80218990 24020002 */  addiu     $v0, $zero, 2
/* 58CC84 80218994 03E00008 */  jr        $ra
/* 58CC88 80218998 27BD0020 */   addiu    $sp, $sp, 0x20
/* 58CC8C 8021899C 00000000 */  nop
