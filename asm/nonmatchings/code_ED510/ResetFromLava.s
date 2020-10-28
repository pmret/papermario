.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel ResetFromLava
/* EE888 802C9ED8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* EE88C 802C9EDC AFBF0020 */  sw        $ra, 0x20($sp)
/* EE890 802C9EE0 AFB3001C */  sw        $s3, 0x1c($sp)
/* EE894 802C9EE4 AFB20018 */  sw        $s2, 0x18($sp)
/* EE898 802C9EE8 AFB10014 */  sw        $s1, 0x14($sp)
/* EE89C 802C9EEC AFB00010 */  sw        $s0, 0x10($sp)
/* EE8A0 802C9EF0 10A0001D */  beqz      $a1, .L802C9F68
/* EE8A4 802C9EF4 8C82000C */   lw       $v0, 0xc($a0)
/* EE8A8 802C9EF8 8C450000 */  lw        $a1, ($v0)
/* EE8AC 802C9EFC 3C12800B */  lui       $s2, 0x800b
/* EE8B0 802C9F00 265242E0 */  addiu     $s2, $s2, 0x42e0
/* EE8B4 802C9F04 0C0B1EAF */  jal       get_variable
/* EE8B8 802C9F08 2413FFFF */   addiu    $s3, $zero, -1
/* EE8BC 802C9F0C 0040882D */  daddu     $s1, $v0, $zero
/* EE8C0 802C9F10 3C01802E */  lui       $at, 0x802e
/* EE8C4 802C9F14 AC31ADA0 */  sw        $s1, -0x5260($at)
.L802C9F18:
/* EE8C8 802C9F18 8E230000 */  lw        $v1, ($s1)
/* EE8CC 802C9F1C 1073000F */  beq       $v1, $s3, .L802C9F5C
/* EE8D0 802C9F20 000310C0 */   sll      $v0, $v1, 3
/* EE8D4 802C9F24 00431023 */  subu      $v0, $v0, $v1
/* EE8D8 802C9F28 8E430004 */  lw        $v1, 4($s2)
/* EE8DC 802C9F2C 00021080 */  sll       $v0, $v0, 2
/* EE8E0 802C9F30 00628021 */  addu      $s0, $v1, $v0
/* EE8E4 802C9F34 86040006 */  lh        $a0, 6($s0)
/* EE8E8 802C9F38 04800003 */  bltz      $a0, .L802C9F48
/* EE8EC 802C9F3C 24050100 */   addiu    $a1, $zero, 0x100
/* EE8F0 802C9F40 0C0B273A */  jal       modify_collider_family_flags
/* EE8F4 802C9F44 0000302D */   daddu    $a2, $zero, $zero
.L802C9F48:
/* EE8F8 802C9F48 8E020000 */  lw        $v0, ($s0)
/* EE8FC 802C9F4C 26310010 */  addiu     $s1, $s1, 0x10
/* EE900 802C9F50 34420100 */  ori       $v0, $v0, 0x100
/* EE904 802C9F54 080B27C6 */  j         .L802C9F18
/* EE908 802C9F58 AE020000 */   sw       $v0, ($s0)
.L802C9F5C:
/* EE90C 802C9F5C 2402FFFF */  addiu     $v0, $zero, -1
/* EE910 802C9F60 3C01802E */  lui       $at, 0x802e
/* EE914 802C9F64 AC22ADA4 */  sw        $v0, -0x525c($at)
.L802C9F68:
/* EE918 802C9F68 3C028016 */  lui       $v0, %hi(gCollisionStatus)
/* EE91C 802C9F6C 2442A550 */  addiu     $v0, $v0, %lo(gCollisionStatus)
/* EE920 802C9F70 94430002 */  lhu       $v1, 2($v0)
/* EE924 802C9F74 30624000 */  andi      $v0, $v1, 0x4000
/* EE928 802C9F78 1440000F */  bnez      $v0, .L802C9FB8
/* EE92C 802C9F7C 0000102D */   daddu    $v0, $zero, $zero
/* EE930 802C9F80 00031400 */  sll       $v0, $v1, 0x10
/* EE934 802C9F84 00022403 */  sra       $a0, $v0, 0x10
/* EE938 802C9F88 000410C0 */  sll       $v0, $a0, 3
/* EE93C 802C9F8C 00441023 */  subu      $v0, $v0, $a0
/* EE940 802C9F90 3C03800B */  lui       $v1, 0x800b
/* EE944 802C9F94 8C6342E4 */  lw        $v1, 0x42e4($v1)
/* EE948 802C9F98 00021080 */  sll       $v0, $v0, 2
/* EE94C 802C9F9C 00628021 */  addu      $s0, $v1, $v0
/* EE950 802C9FA0 8E020000 */  lw        $v0, ($s0)
/* EE954 802C9FA4 30420100 */  andi      $v0, $v0, 0x100
/* EE958 802C9FA8 10400003 */  beqz      $v0, .L802C9FB8
/* EE95C 802C9FAC 0000102D */   daddu    $v0, $zero, $zero
/* EE960 802C9FB0 3C01802E */  lui       $at, 0x802e
/* EE964 802C9FB4 AC24ADA4 */  sw        $a0, -0x525c($at)
.L802C9FB8:
/* EE968 802C9FB8 8FBF0020 */  lw        $ra, 0x20($sp)
/* EE96C 802C9FBC 8FB3001C */  lw        $s3, 0x1c($sp)
/* EE970 802C9FC0 8FB20018 */  lw        $s2, 0x18($sp)
/* EE974 802C9FC4 8FB10014 */  lw        $s1, 0x14($sp)
/* EE978 802C9FC8 8FB00010 */  lw        $s0, 0x10($sp)
/* EE97C 802C9FCC 03E00008 */  jr        $ra
/* EE980 802C9FD0 27BD0028 */   addiu    $sp, $sp, 0x28
