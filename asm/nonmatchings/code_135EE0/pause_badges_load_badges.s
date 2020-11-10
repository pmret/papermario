.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_badges_load_badges
/* 13C0CC 80248D8C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 13C0D0 80248D90 AFB00010 */  sw        $s0, 0x10($sp)
/* 13C0D4 80248D94 AFB10014 */  sw        $s1, 0x14($sp)
/* 13C0D8 80248D98 3C118011 */  lui       $s1, %hi(gPlayerData)
/* 13C0DC 80248D9C 2631F290 */  addiu     $s1, $s1, %lo(gPlayerData)
/* 13C0E0 80248DA0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 13C0E4 80248DA4 3C018027 */  lui       $at, 0x8027
/* 13C0E8 80248DA8 AC200388 */  sw        $zero, 0x388($at)
/* 13C0EC 80248DAC 14800014 */  bnez      $a0, .L80248E00
/* 13C0F0 80248DB0 0000802D */   daddu    $s0, $zero, $zero
/* 13C0F4 80248DB4 0200202D */  daddu     $a0, $s0, $zero
/* 13C0F8 80248DB8 0220302D */  daddu     $a2, $s1, $zero
/* 13C0FC 80248DBC 3C058027 */  lui       $a1, 0x8027
/* 13C100 80248DC0 24A50180 */  addiu     $a1, $a1, 0x180
.L80248DC4:
/* 13C104 80248DC4 84C200B4 */  lh        $v0, 0xb4($a2)
/* 13C108 80248DC8 94C300B4 */  lhu       $v1, 0xb4($a2)
/* 13C10C 80248DCC 10400007 */  beqz      $v0, .L80248DEC
/* 13C110 80248DD0 24840001 */   addiu    $a0, $a0, 1
/* 13C114 80248DD4 28420155 */  slti      $v0, $v0, 0x155
/* 13C118 80248DD8 10400019 */  beqz      $v0, .L80248E40
/* 13C11C 80248DDC 00000000 */   nop      
/* 13C120 80248DE0 A4A30000 */  sh        $v1, ($a1)
/* 13C124 80248DE4 24A50002 */  addiu     $a1, $a1, 2
/* 13C128 80248DE8 26100001 */  addiu     $s0, $s0, 1
.L80248DEC:
/* 13C12C 80248DEC 28820080 */  slti      $v0, $a0, 0x80
/* 13C130 80248DF0 1440FFF4 */  bnez      $v0, .L80248DC4
/* 13C134 80248DF4 24C60002 */   addiu    $a2, $a2, 2
/* 13C138 80248DF8 08092390 */  j         .L80248E40
/* 13C13C 80248DFC 00000000 */   nop      
.L80248E00:
/* 13C140 80248E00 0C091C2C */  jal       pause_badges_count_equipped
/* 13C144 80248E04 00000000 */   nop      
/* 13C148 80248E08 26260208 */  addiu     $a2, $s1, 0x208
/* 13C14C 80248E0C 0000202D */  daddu     $a0, $zero, $zero
/* 13C150 80248E10 3C058027 */  lui       $a1, 0x8027
/* 13C154 80248E14 24A50180 */  addiu     $a1, $a1, 0x180
.L80248E18:
/* 13C158 80248E18 84C20000 */  lh        $v0, ($a2)
/* 13C15C 80248E1C 94C30000 */  lhu       $v1, ($a2)
/* 13C160 80248E20 10400004 */  beqz      $v0, .L80248E34
/* 13C164 80248E24 24840001 */   addiu    $a0, $a0, 1
/* 13C168 80248E28 A4A30000 */  sh        $v1, ($a1)
/* 13C16C 80248E2C 24A50002 */  addiu     $a1, $a1, 2
/* 13C170 80248E30 26100001 */  addiu     $s0, $s0, 1
.L80248E34:
/* 13C174 80248E34 28820040 */  slti      $v0, $a0, 0x40
/* 13C178 80248E38 1440FFF7 */  bnez      $v0, .L80248E18
/* 13C17C 80248E3C 24C60002 */   addiu    $a2, $a2, 2
.L80248E40:
/* 13C180 80248E40 16000004 */  bnez      $s0, .L80248E54
/* 13C184 80248E44 24027FFE */   addiu    $v0, $zero, 0x7ffe
/* 13C188 80248E48 3C018027 */  lui       $at, 0x8027
/* 13C18C 80248E4C A4220180 */  sh        $v0, 0x180($at)
/* 13C190 80248E50 24100001 */  addiu     $s0, $zero, 1
.L80248E54:
/* 13C194 80248E54 3C018027 */  lui       $at, 0x8027
/* 13C198 80248E58 A4300384 */  sh        $s0, 0x384($at)
/* 13C19C 80248E5C 0200202D */  daddu     $a0, $s0, $zero
/* 13C1A0 80248E60 28820080 */  slti      $v0, $a0, 0x80
/* 13C1A4 80248E64 1040000A */  beqz      $v0, .L80248E90
/* 13C1A8 80248E68 24057FFF */   addiu    $a1, $zero, 0x7fff
/* 13C1AC 80248E6C 3C038027 */  lui       $v1, 0x8027
/* 13C1B0 80248E70 24630180 */  addiu     $v1, $v1, 0x180
/* 13C1B4 80248E74 00041040 */  sll       $v0, $a0, 1
/* 13C1B8 80248E78 00431821 */  addu      $v1, $v0, $v1
.L80248E7C:
/* 13C1BC 80248E7C A4650000 */  sh        $a1, ($v1)
/* 13C1C0 80248E80 24840001 */  addiu     $a0, $a0, 1
/* 13C1C4 80248E84 28820080 */  slti      $v0, $a0, 0x80
/* 13C1C8 80248E88 1440FFFC */  bnez      $v0, .L80248E7C
/* 13C1CC 80248E8C 24630002 */   addiu    $v1, $v1, 2
.L80248E90:
/* 13C1D0 80248E90 3C058027 */  lui       $a1, 0x8027
/* 13C1D4 80248E94 24A50288 */  addiu     $a1, $a1, 0x288
/* 13C1D8 80248E98 0000202D */  daddu     $a0, $zero, $zero
/* 13C1DC 80248E9C 3C078027 */  lui       $a3, 0x8027
/* 13C1E0 80248EA0 24E70384 */  addiu     $a3, $a3, 0x384
/* 13C1E4 80248EA4 24060001 */  addiu     $a2, $zero, 1
/* 13C1E8 80248EA8 24090008 */  addiu     $t1, $zero, 8
/* 13C1EC 80248EAC 24080008 */  addiu     $t0, $zero, 8
/* 13C1F0 80248EB0 00A81821 */  addu      $v1, $a1, $t0
/* 13C1F4 80248EB4 3C018027 */  lui       $at, 0x8027
/* 13C1F8 80248EB8 AC200378 */  sw        $zero, 0x378($at)
/* 13C1FC 80248EBC 3C018027 */  lui       $at, 0x8027
/* 13C200 80248EC0 AC200380 */  sw        $zero, 0x380($at)
/* 13C204 80248EC4 3C018027 */  lui       $at, 0x8027
/* 13C208 80248EC8 AC20037C */  sw        $zero, 0x37c($at)
/* 13C20C 80248ECC 3C018027 */  lui       $at, 0x8027
/* 13C210 80248ED0 AC200394 */  sw        $zero, 0x394($at)
/* 13C214 80248ED4 3C018027 */  lui       $at, 0x8027
/* 13C218 80248ED8 AC200280 */  sw        $zero, 0x280($at)
.L80248EDC:
/* 13C21C 80248EDC 84E20000 */  lh        $v0, ($a3)
/* 13C220 80248EE0 04420001 */  bltzl     $v0, .L80248EE8
/* 13C224 80248EE4 24420007 */   addiu    $v0, $v0, 7
.L80248EE8:
/* 13C228 80248EE8 000210C3 */  sra       $v0, $v0, 3
/* 13C22C 80248EEC 0082102A */  slt       $v0, $a0, $v0
/* 13C230 80248EF0 1040000B */  beqz      $v0, .L80248F20
/* 13C234 80248EF4 000410C0 */   sll      $v0, $a0, 3
/* 13C238 80248EF8 24840001 */  addiu     $a0, $a0, 1
/* 13C23C 80248EFC A062FFF9 */  sb        $v0, -7($v1)
/* 13C240 80248F00 A066FFFA */  sb        $a2, -6($v1)
/* 13C244 80248F04 A069FFFB */  sb        $t1, -5($v1)
/* 13C248 80248F08 A0A60000 */  sb        $a2, ($a1)
/* 13C24C 80248F0C AC62FFFC */  sw        $v0, -4($v1)
/* 13C250 80248F10 AC680000 */  sw        $t0, ($v1)
/* 13C254 80248F14 2463000C */  addiu     $v1, $v1, 0xc
/* 13C258 80248F18 080923B7 */  j         .L80248EDC
/* 13C25C 80248F1C 24A5000C */   addiu    $a1, $a1, 0xc
.L80248F20:
/* 13C260 80248F20 94E20000 */  lhu       $v0, ($a3)
/* 13C264 80248F24 30420007 */  andi      $v0, $v0, 7
/* 13C268 80248F28 10400016 */  beqz      $v0, .L80248F84
/* 13C26C 80248F2C 000418C0 */   sll      $v1, $a0, 3
/* 13C270 80248F30 24020001 */  addiu     $v0, $zero, 1
/* 13C274 80248F34 A0A30001 */  sb        $v1, 1($a1)
/* 13C278 80248F38 A0A20002 */  sb        $v0, 2($a1)
/* 13C27C 80248F3C A0A20000 */  sb        $v0, ($a1)
/* 13C280 80248F40 84E60000 */  lh        $a2, ($a3)
/* 13C284 80248F44 ACA30004 */  sw        $v1, 4($a1)
/* 13C288 80248F48 04C10002 */  bgez      $a2, .L80248F54
/* 13C28C 80248F4C 00C0102D */   daddu    $v0, $a2, $zero
/* 13C290 80248F50 24C20007 */  addiu     $v0, $a2, 7
.L80248F54:
/* 13C294 80248F54 000210C3 */  sra       $v0, $v0, 3
/* 13C298 80248F58 000210C0 */  sll       $v0, $v0, 3
/* 13C29C 80248F5C 00C21023 */  subu      $v0, $a2, $v0
/* 13C2A0 80248F60 00021400 */  sll       $v0, $v0, 0x10
/* 13C2A4 80248F64 00021403 */  sra       $v0, $v0, 0x10
/* 13C2A8 80248F68 ACA20008 */  sw        $v0, 8($a1)
/* 13C2AC 80248F6C 90A2000B */  lbu       $v0, 0xb($a1)
/* 13C2B0 80248F70 24840001 */  addiu     $a0, $a0, 1
/* 13C2B4 80248F74 080923E0 */  j         .L80248F80
/* 13C2B8 80248F78 A0A20003 */   sb       $v0, 3($a1)
.L80248F7C:
/* 13C2BC 80248F7C 24840001 */  addiu     $a0, $a0, 1
.L80248F80:
/* 13C2C0 80248F80 24A5000C */  addiu     $a1, $a1, 0xc
.L80248F84:
/* 13C2C4 80248F84 28820014 */  slti      $v0, $a0, 0x14
/* 13C2C8 80248F88 5440FFFC */  bnel      $v0, $zero, .L80248F7C
/* 13C2CC 80248F8C A0A00000 */   sb       $zero, ($a1)
/* 13C2D0 80248F90 0000202D */  daddu     $a0, $zero, $zero
/* 13C2D4 80248F94 0C091C5A */  jal       pause_badges_get_pos_y
/* 13C2D8 80248F98 0080282D */   daddu    $a1, $a0, $zero
/* 13C2DC 80248F9C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 13C2E0 80248FA0 8FB10014 */  lw        $s1, 0x14($sp)
/* 13C2E4 80248FA4 8FB00010 */  lw        $s0, 0x10($sp)
/* 13C2E8 80248FA8 3C018027 */  lui       $at, %hi(gBadgeMenuCurrentScrollPos)
/* 13C2EC 80248FAC AC22038C */  sw        $v0, %lo(gBadgeMenuCurrentScrollPos)($at)
/* 13C2F0 80248FB0 3C018027 */  lui       $at, %hi(gBadgeMenuTargetScrollPos)
/* 13C2F4 80248FB4 AC220390 */  sw        $v0, %lo(gBadgeMenuTargetScrollPos)($at)
/* 13C2F8 80248FB8 03E00008 */  jr        $ra
/* 13C2FC 80248FBC 27BD0020 */   addiu    $sp, $sp, 0x20
