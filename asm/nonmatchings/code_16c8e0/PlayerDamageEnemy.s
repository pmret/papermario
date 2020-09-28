.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel PlayerDamageEnemy
/* 1A2B40 80274260 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 1A2B44 80274264 AFB20018 */  sw        $s2, 0x18($sp)
/* 1A2B48 80274268 0080902D */  daddu     $s2, $a0, $zero
/* 1A2B4C 8027426C AFBF0020 */  sw        $ra, 0x20($sp)
/* 1A2B50 80274270 AFB3001C */  sw        $s3, 0x1c($sp)
/* 1A2B54 80274274 AFB10014 */  sw        $s1, 0x14($sp)
/* 1A2B58 80274278 AFB00010 */  sw        $s0, 0x10($sp)
/* 1A2B5C 8027427C 8E50000C */  lw        $s0, 0xc($s2)
/* 1A2B60 80274280 3C11800E */  lui       $s1, %hi(gBattleStatus)
/* 1A2B64 80274284 2631C070 */  addiu     $s1, $s1, %lo(gBattleStatus)
/* 1A2B68 80274288 8E130000 */  lw        $s3, ($s0)
/* 1A2B6C 8027428C 26100004 */  addiu     $s0, $s0, 4
/* 1A2B70 80274290 8E020000 */  lw        $v0, ($s0)
/* 1A2B74 80274294 26100004 */  addiu     $s0, $s0, 4
/* 1A2B78 80274298 AE220188 */  sw        $v0, 0x188($s1)
/* 1A2B7C 8027429C 8E020000 */  lw        $v0, ($s0)
/* 1A2B80 802742A0 26100004 */  addiu     $s0, $s0, 4
/* 1A2B84 802742A4 AE22018C */  sw        $v0, 0x18c($s1)
/* 1A2B88 802742A8 8E020000 */  lw        $v0, ($s0)
/* 1A2B8C 802742AC 26100004 */  addiu     $s0, $s0, 4
/* 1A2B90 802742B0 AE220190 */  sw        $v0, 0x190($s1)
/* 1A2B94 802742B4 8E050000 */  lw        $a1, ($s0)
/* 1A2B98 802742B8 0C0B1EAF */  jal       get_variable
/* 1A2B9C 802742BC 26100004 */   addiu    $s0, $s0, 4
/* 1A2BA0 802742C0 A622017E */  sh        $v0, 0x17e($s1)
/* 1A2BA4 802742C4 A2200198 */  sb        $zero, 0x198($s1)
/* 1A2BA8 802742C8 8E100000 */  lw        $s0, ($s0)
/* 1A2BAC 802742CC 24020030 */  addiu     $v0, $zero, 0x30
/* 1A2BB0 802742D0 32030030 */  andi      $v1, $s0, 0x30
/* 1A2BB4 802742D4 54620004 */  bnel      $v1, $v0, .L802742E8
/* 1A2BB8 802742D8 32020010 */   andi     $v0, $s0, 0x10
/* 1A2BBC 802742DC 8E220000 */  lw        $v0, ($s1)
/* 1A2BC0 802742E0 0809D0CA */  j         .L80274328
/* 1A2BC4 802742E4 34420030 */   ori      $v0, $v0, 0x30
.L802742E8:
/* 1A2BC8 802742E8 10400004 */  beqz      $v0, .L802742FC
/* 1A2BCC 802742EC 2403FFDF */   addiu    $v1, $zero, -0x21
/* 1A2BD0 802742F0 8E220000 */  lw        $v0, ($s1)
/* 1A2BD4 802742F4 0809D0C9 */  j         .L80274324
/* 1A2BD8 802742F8 34420010 */   ori      $v0, $v0, 0x10
.L802742FC:
/* 1A2BDC 802742FC 32020020 */  andi      $v0, $s0, 0x20
/* 1A2BE0 80274300 10400005 */  beqz      $v0, .L80274318
/* 1A2BE4 80274304 2403FFEF */   addiu    $v1, $zero, -0x11
/* 1A2BE8 80274308 8E220000 */  lw        $v0, ($s1)
/* 1A2BEC 8027430C 00431024 */  and       $v0, $v0, $v1
/* 1A2BF0 80274310 0809D0CA */  j         .L80274328
/* 1A2BF4 80274314 34420020 */   ori      $v0, $v0, 0x20
.L80274318:
/* 1A2BF8 80274318 8E220000 */  lw        $v0, ($s1)
/* 1A2BFC 8027431C 00431024 */  and       $v0, $v0, $v1
/* 1A2C00 80274320 2403FFDF */  addiu     $v1, $zero, -0x21
.L80274324:
/* 1A2C04 80274324 00431024 */  and       $v0, $v0, $v1
.L80274328:
/* 1A2C08 80274328 AE220000 */  sw        $v0, ($s1)
/* 1A2C0C 8027432C 32020040 */  andi      $v0, $s0, 0x40
/* 1A2C10 80274330 10400007 */  beqz      $v0, .L80274350
/* 1A2C14 80274334 2404FFBF */   addiu    $a0, $zero, -0x41
/* 1A2C18 80274338 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 1A2C1C 8027433C 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 1A2C20 80274340 8C620000 */  lw        $v0, ($v1)
/* 1A2C24 80274344 34420040 */  ori       $v0, $v0, 0x40
/* 1A2C28 80274348 0809D0D9 */  j         .L80274364
/* 1A2C2C 8027434C AC620000 */   sw       $v0, ($v1)
.L80274350:
/* 1A2C30 80274350 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 1A2C34 80274354 2442C070 */  addiu     $v0, $v0, %lo(gBattleStatus)
/* 1A2C38 80274358 8C430000 */  lw        $v1, ($v0)
/* 1A2C3C 8027435C 00641824 */  and       $v1, $v1, $a0
/* 1A2C40 80274360 AC430000 */  sw        $v1, ($v0)
.L80274364:
/* 1A2C44 80274364 32020200 */  andi      $v0, $s0, 0x200
/* 1A2C48 80274368 10400007 */  beqz      $v0, .L80274388
/* 1A2C4C 8027436C 2404FDFF */   addiu    $a0, $zero, -0x201
/* 1A2C50 80274370 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 1A2C54 80274374 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 1A2C58 80274378 8C620000 */  lw        $v0, ($v1)
/* 1A2C5C 8027437C 34420200 */  ori       $v0, $v0, 0x200
/* 1A2C60 80274380 0809D0E7 */  j         .L8027439C
/* 1A2C64 80274384 AC620000 */   sw       $v0, ($v1)
.L80274388:
/* 1A2C68 80274388 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 1A2C6C 8027438C 2442C070 */  addiu     $v0, $v0, %lo(gBattleStatus)
/* 1A2C70 80274390 8C430000 */  lw        $v1, ($v0)
/* 1A2C74 80274394 00641824 */  and       $v1, $v1, $a0
/* 1A2C78 80274398 AC430000 */  sw        $v1, ($v0)
.L8027439C:
/* 1A2C7C 8027439C 32020080 */  andi      $v0, $s0, 0x80
/* 1A2C80 802743A0 10400007 */  beqz      $v0, .L802743C0
/* 1A2C84 802743A4 2404FF7F */   addiu    $a0, $zero, -0x81
/* 1A2C88 802743A8 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 1A2C8C 802743AC 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 1A2C90 802743B0 8C620000 */  lw        $v0, ($v1)
/* 1A2C94 802743B4 34420080 */  ori       $v0, $v0, 0x80
/* 1A2C98 802743B8 0809D0F5 */  j         .L802743D4
/* 1A2C9C 802743BC AC620000 */   sw       $v0, ($v1)
.L802743C0:
/* 1A2CA0 802743C0 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 1A2CA4 802743C4 2442C070 */  addiu     $v0, $v0, %lo(gBattleStatus)
/* 1A2CA8 802743C8 8C430000 */  lw        $v1, ($v0)
/* 1A2CAC 802743CC 00641824 */  and       $v1, $v1, $a0
/* 1A2CB0 802743D0 AC430000 */  sw        $v1, ($v0)
.L802743D4:
/* 1A2CB4 802743D4 32020800 */  andi      $v0, $s0, 0x800
/* 1A2CB8 802743D8 10400007 */  beqz      $v0, .L802743F8
/* 1A2CBC 802743DC 2404F7FF */   addiu    $a0, $zero, -0x801
/* 1A2CC0 802743E0 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 1A2CC4 802743E4 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 1A2CC8 802743E8 8C620000 */  lw        $v0, ($v1)
/* 1A2CCC 802743EC 34420800 */  ori       $v0, $v0, 0x800
/* 1A2CD0 802743F0 0809D103 */  j         .L8027440C
/* 1A2CD4 802743F4 AC620000 */   sw       $v0, ($v1)
.L802743F8:
/* 1A2CD8 802743F8 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 1A2CDC 802743FC 2442C070 */  addiu     $v0, $v0, %lo(gBattleStatus)
/* 1A2CE0 80274400 8C430000 */  lw        $v1, ($v0)
/* 1A2CE4 80274404 00641824 */  and       $v1, $v1, $a0
/* 1A2CE8 80274408 AC430000 */  sw        $v1, ($v0)
.L8027440C:
/* 1A2CEC 8027440C 0C09A75B */  jal       get_actor
/* 1A2CF0 80274410 8E440148 */   lw       $a0, 0x148($s2)
/* 1A2CF4 80274414 94430428 */  lhu       $v1, 0x428($v0)
/* 1A2CF8 80274418 A62301A0 */  sh        $v1, 0x1a0($s1)
/* 1A2CFC 8027441C 92230193 */  lbu       $v1, 0x193($s1)
/* 1A2D00 80274420 90420426 */  lbu       $v0, 0x426($v0)
/* 1A2D04 80274424 A2230194 */  sb        $v1, 0x194($s1)
/* 1A2D08 80274428 306300FF */  andi      $v1, $v1, 0xff
/* 1A2D0C 8027442C A22201A2 */  sb        $v0, 0x1a2($s1)
/* 1A2D10 80274430 240200FF */  addiu     $v0, $zero, 0xff
/* 1A2D14 80274434 50620001 */  beql      $v1, $v0, .L8027443C
/* 1A2D18 80274438 A2200194 */   sb       $zero, 0x194($s1)
.L8027443C:
/* 1A2D1C 8027443C 8E220190 */  lw        $v0, 0x190($s1)
/* 1A2D20 80274440 30420F00 */  andi      $v0, $v0, 0xf00
/* 1A2D24 80274444 00021203 */  sra       $v0, $v0, 8
/* 1A2D28 80274448 0C09C651 */  jal       calc_player_damage_enemy
/* 1A2D2C 8027444C A2220195 */   sb       $v0, 0x195($s1)
/* 1A2D30 80274450 0440000B */  bltz      $v0, .L80274480
/* 1A2D34 80274454 0240202D */   daddu    $a0, $s2, $zero
/* 1A2D38 80274458 0260282D */  daddu     $a1, $s3, $zero
/* 1A2D3C 8027445C 0C0B2026 */  jal       set_variable
/* 1A2D40 80274460 0040302D */   daddu    $a2, $v0, $zero
/* 1A2D44 80274464 0C0B1069 */  jal       does_script_exist_by_ref
/* 1A2D48 80274468 0240202D */   daddu    $a0, $s2, $zero
/* 1A2D4C 8027446C 0040182D */  daddu     $v1, $v0, $zero
/* 1A2D50 80274470 10600004 */  beqz      $v1, .L80274484
/* 1A2D54 80274474 240200FF */   addiu    $v0, $zero, 0xff
/* 1A2D58 80274478 0809D121 */  j         .L80274484
/* 1A2D5C 8027447C 24020002 */   addiu    $v0, $zero, 2
.L80274480:
/* 1A2D60 80274480 240200FF */  addiu     $v0, $zero, 0xff
.L80274484:
/* 1A2D64 80274484 8FBF0020 */  lw        $ra, 0x20($sp)
/* 1A2D68 80274488 8FB3001C */  lw        $s3, 0x1c($sp)
/* 1A2D6C 8027448C 8FB20018 */  lw        $s2, 0x18($sp)
/* 1A2D70 80274490 8FB10014 */  lw        $s1, 0x14($sp)
/* 1A2D74 80274494 8FB00010 */  lw        $s0, 0x10($sp)
/* 1A2D78 80274498 03E00008 */  jr        $ra
/* 1A2D7C 8027449C 27BD0028 */   addiu    $sp, $sp, 0x28
