.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel setup_item_popup
/* 800F4 800E6C44 0000402D */  daddu     $t0, $zero, $zero
/* 800F8 800E6C48 0100302D */  daddu     $a2, $t0, $zero
/* 800FC 800E6C4C 3C0B8008 */  lui       $t3, %hi(gItemTable)
/* 80100 800E6C50 256B78E0 */  addiu     $t3, $t3, %lo(gItemTable)
/* 80104 800E6C54 3C0A8009 */  lui       $t2, %hi(D_8008A680)
/* 80108 800E6C58 254AA680 */  addiu     $t2, $t2, %lo(D_8008A680)
/* 8010C 800E6C5C 24090001 */  addiu     $t1, $zero, 1
/* 80110 800E6C60 3C078011 */  lui       $a3, %hi(gPlayerData)
/* 80114 800E6C64 24E7F290 */  addiu     $a3, $a3, %lo(gPlayerData)
.L800E6C68:
/* 80118 800E6C68 84E201B4 */  lh        $v0, 0x1b4($a3)
/* 8011C 800E6C6C 50400018 */  beql      $v0, $zero, .L800E6CD0
/* 80120 800E6C70 24C60001 */   addiu    $a2, $a2, 1
/* 80124 800E6C74 00021140 */  sll       $v0, $v0, 5
/* 80128 800E6C78 004B2821 */  addu      $a1, $v0, $t3
/* 8012C 800E6C7C 84A20004 */  lh        $v0, 4($a1)
/* 80130 800E6C80 94A30018 */  lhu       $v1, 0x18($a1)
/* 80134 800E6C84 000210C0 */  sll       $v0, $v0, 3
/* 80138 800E6C88 30630001 */  andi      $v1, $v1, 1
/* 8013C 800E6C8C 10600005 */  beqz      $v1, .L800E6CA4
/* 80140 800E6C90 004A1021 */   addu     $v0, $v0, $t2
/* 80144 800E6C94 8C420000 */  lw        $v0, ($v0)
/* 80148 800E6C98 AC860108 */  sw        $a2, 0x108($a0)
/* 8014C 800E6C9C 08039B2C */  j         .L800E6CB0
/* 80150 800E6CA0 AC89018C */   sw       $t1, 0x18c($a0)
.L800E6CA4:
/* 80154 800E6CA4 8C420004 */  lw        $v0, 4($v0)
/* 80158 800E6CA8 AC860108 */  sw        $a2, 0x108($a0)
/* 8015C 800E6CAC AC80018C */  sw        $zero, 0x18c($a0)
.L800E6CB0:
/* 80160 800E6CB0 AC820000 */  sw        $v0, ($a0)
/* 80164 800E6CB4 8CA20000 */  lw        $v0, ($a1)
/* 80168 800E6CB8 AC820084 */  sw        $v0, 0x84($a0)
/* 8016C 800E6CBC 8CA20014 */  lw        $v0, 0x14($a1)
/* 80170 800E6CC0 25080001 */  addiu     $t0, $t0, 1
/* 80174 800E6CC4 AC820294 */  sw        $v0, 0x294($a0)
/* 80178 800E6CC8 24840004 */  addiu     $a0, $a0, 4
/* 8017C 800E6CCC 24C60001 */  addiu     $a2, $a2, 1
.L800E6CD0:
/* 80180 800E6CD0 28C2000A */  slti      $v0, $a2, 0xa
/* 80184 800E6CD4 1440FFE4 */  bnez      $v0, .L800E6C68
/* 80188 800E6CD8 24E70002 */   addiu    $a3, $a3, 2
/* 8018C 800E6CDC 03E00008 */  jr        $ra
/* 80190 800E6CE0 0100102D */   daddu    $v0, $t0, $zero
