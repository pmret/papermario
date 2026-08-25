# Battle States

This document describes the battle state machine using a series of flowcharts.
Each node represents a state, and arrows represent transitions.
Bold arrows highlight the typical or most common transition paths.
The full state machine will be presented at the end, after we build up the major components.

## Initiating Battles

All battles begin in `BATTLE_STATE_START`, set during `load_battle_section`. After all actors are created,
this state checks whether the battle was initiated with a 'first strike' and selects the appropriate opening state.
Unless the battle ends with the first strike, the battle loop will begin with the first visit to `BATTLE_STATE_BEGIN_TURN`.

```mermaid
flowchart TD
    NormalStart[Start]
    FS_Player[First Strike]
    FS_Partner[Partner First Strike]
    FS_Enemy[Enemy First Strike]
    BeginTurn[Begin Turn]

    NormalStart ==> BeginTurn
    NormalStart --> FS_Enemy
    NormalStart --> FS_Player
    FS_Player --> FS_Partner
    FS_Player --> BeginTurn
    FS_Partner --> BeginTurn
    FS_Enemy --> BeginTurn
```
## Ending Battles

Battles are ended in `BATTLE_STATE_END_BATTLE` where the game mode is changed.

A battle ends when one of the following conditions is met:
1. The player is defeated (Defeat)
2. All enemies are defeated (Victory)
3. Run Away is successful (Flee)

The first two conditions are checked at certain points during multiple battle states; typically when an actor begins or
their turn, finishes using a move, or when control is being transfered to another actor. A full table of which states
may trigger which ending is presented here:

| State | Checks Victory | Checks Defeat |
|-------|:--------------:|:--------------:|
| FIRST_STRIKE               | X | X |
| PARTNER_FIRST_STRIKE       | X | X |
| ENEMY_FIRST_STRIKE         | X | X |
| BEGIN_TURN                 | X |   |
| BEGIN_PLAYER_TURN          | X | X |
| BEGIN_PARTNER_TURN         | X | X |
| PLAYER_MOVE                |   | X |
| PARTNER_MOVE               |   | X |
| END_PLAYER_TURN            | X |   |
| END_PARTNER_TURN           | X |   |
| TRANSFER_TURN              | X | X |
| ENEMY_MOVE                 | X | X |

Defeat is detected via `btl_check_player_defeated`, which initiates a transition to `BATTLE_STATE_DEFEAT` when
the player has zero HP.

Victory is detected via `btl_check_enemies_defeated`, which initiates a transition to `BATTLE_STATE_VICTORY` when
no valid defeatable enemies are left.

Some battles are scripted to end when certain conditions are met (see final_bowser_1 in kpa2).
This is done by setting `ACTOR_FLAG_NO_DMG_APPLY` to the boss actor and then setting `BS_FLAGS1_BATTLE_FLED`.
This counts as the enemy fleeing. On the next victory check, `btl_check_enemies_defeated` will find no enemies
left and trigger a Victory.

```mermaid
flowchart TD
    PlayerDefeated([Player Defeated])
    EnemiesDefeated([All Enemies Defeated])
    BattleMenu([Strategies Menu])
    Transfer([Transfer Turn])
    RunAway[Run Away]
    Victory[Victory]
    Defeat[Defeat]
    EndBattle[End Battle]
    Celebration[Celebration]

    EnemiesDefeated --> Victory
    PlayerDefeated ---> Defeat
    BattleMenu ---> RunAway

    RunAway --> |Failed| Transfer
    RunAway --> EndBattle

    Celebration --> EndBattle
    Defeat --> EndBattle

    Victory --> |Skip Celebration| EndBattle
    Victory --> Celebration
```

## Basic Turn Loop

Each turn has phases where the player may act, the partner may act, and the enemies act. If the player or partner
cannot act, their phase is skipped. They can also change the order in which their actions occur via swap. After the
partner acts, the `BATTLE_STATE_TRANSFER_TURN` state is used to select the next actor. This allows a player to go
after the partner and supports the swapped positions in a Peach battle.

**Note:** the nodes in this chart are simplified pseudo-states which do not correspond to literal battle states.
We'll go over the full state machine in a coming section.

```mermaid
flowchart TD
    BeginTurn[Begin Turn]
    BeginPlayer[Begin Player]
    PlayerMenu[Player Menu]
    PlayerActs[Player Acts]
    BeginPartner[Begin Partner]
    PartnerMenu[Partner Menu]
    PartnerActs[Partner Acts]
    TransferTurn[Transfer Turn]
    EnemiesAct[Enemies Act]
    EndTurn[End Turn]

    BeginTurn ==> BeginPlayer
    BeginPlayer --> |Player Can't Act| BeginPartner

    BeginPlayer ==> PlayerMenu
    PlayerMenu ==> PlayerActs
    PlayerMenu ---> |Swap| BeginPartner
    PlayerActs ==> BeginPartner


    BeginPartner --> |Partner Can't Act| TransferTurn
    BeginPartner ==> PartnerMenu
    PartnerMenu ==> PartnerActs
    PartnerMenu ---> |Swap| BeginPlayer
    PartnerActs ==> TransferTurn
    TransferTurn ==> EnemiesAct
    TransferTurn --> |Player Can Act| BeginPlayer
    TransferTurn --> |Partner Can Act| BeginPartner
    EnemiesAct ==> EndTurn
    EndTurn ==> BeginTurn
```

## Enemy Actors

Each turn ends with the Enemy phase, where each enemy actor has an opportunity to act. Since their actions are
determined by their move scripts, this portion of the battle state machine is very simple. An enemy is selected
in `BATTLE_STATE_NEXT_ENEMY` and takes their turn with `BATTLE_STATE_ENEMY_MOVE`. This is repeated until all
enemies have acted, and then the turn ends.

```mermaid
flowchart TD
    TransferTurn[Transfer Turn]
    NextEnemy[Next Enemy]
    EnemyMove[Enemy Move]
    EndTurn[End Turn]

    TransferTurn ==> NextEnemy
    NextEnemy ==> EnemyMove
    EnemyMove ==> NextEnemy
    NextEnemy ==> |All Done| EndTurn
```

## Player and Partner Actors

Player and partner actors both perform actions during the first part of each turn. Since the player controls these
actors, their state machines are much more complicated than the enemies'.
Both use roughly the following states:

```mermaid
flowchart TD
    Begin[Begin]
    SwitchThis[Switch to Actor]
    PrepareMenu[Prepare Menu]
    Menu[Menu]
    SelectTarget[Select Target]
    Move[Move]
    ChangePartner[Change Partner]
    SwitchToOther([Switch to Other])
    SwitchFromOther([Switch from Other])
    End[End]

    Begin ==> SwitchThis
    Begin --> |Can't Act| End

    SwitchFromOther --> |Swap| SwitchThis
    SwitchThis ==> PrepareMenu
    PrepareMenu ===> Menu

    Menu -----> |Do Nothing| End
    Menu --> |Swap| SwitchToOther
    Menu ---> ChangePartner
    Menu ==> SelectTarget

    SelectTarget ==>  Move
    SelectTarget -->  |Cancel| Menu

    Move ==> End

    End --> |Extra Action| PrepareMenu

    ChangePartner --> |Quick Change| PrepareMenu
    ChangePartner --> End
```

## Full State Machine

This chart combines all the components we've introduced.
The full turn loop is evident as the state machine loops through `BATTLE_STATE_BEGIN_TURN` from `BATTLE_STATE_END_TURN`
once per turn.

Note: this chart leaves out edges pertaining to Peach battles, which have their own menu states, exchange BeginPlayer
and BeginPartner, and route through TransferTurn after player actions (as partner actions usually do).

```mermaid
flowchart TD
    subgraph SG_Start[ ]
        NormalStart[Start]
        FS_Player[First Strike]
        FS_Partner[Partner First Strike]
        FS_Enemy[Enemy First Strike]
    end
    BeginTurn[Begin Turn]
    EndTurn[End Turn]
    TransferTurn[Transfer Turn]
    BeginPlayer[Begin Player Turn]
    BeginPartner[Begin Partner Turn]
    subgraph SG_Player[ ]
        SwitchPlayer[Switch to Player]
        PrepareMenu1["Prepare Menu (Player)"]
        PlayerMenu[Player Menu]
        %% PeachMenu[Peach Menu]
        SelectTarget1[Select Target]
        PlayerMove[Player Move]
        ChangePartner1[Change Partner]
        RunAway[Run Away]
        Defend[Defend]
        EndPlayer[End Player Turn]
    end
    subgraph SG_Partner[ ]
        SwitchPartner[Switch to Partner]
        PrepareMenu2["Prepare Menu (Partner)"]
        PartnerMenu[Partner Menu]
        %% TwinkMenu[Twink Menu]
        SelectTarget2["Select Target (Partner)"]
        PartnerMove[Partner Move]
        ChangePartner2[Change Partner]
        EndPartner[End Partner Turn]
    end
    subgraph SG_Enemy[ ]
        NextEnemy[Next Enemy]
        EnemyMove[Enemy Move]
    end

    subgraph SG_End[ ]
        PlayerDefeated([Player Defeated])
        EnemiesDefeated([All Enemies Defeated])
        Victory[Victory]
        Celebration[Celebration]
        Defeat[Defeat]
        EndBattle[End Battle]
        EndDemo[End Demo]
        EndTraining[End Training]
    end

    NormalStart ==> BeginTurn
    NormalStart --> FS_Enemy
    NormalStart --> FS_Player
    FS_Player --> FS_Partner
    FS_Player --> BeginTurn
    FS_Partner --> BeginTurn
    FS_Enemy --> BeginTurn

    BeginTurn ==> BeginPlayer
    BeginTurn --> |Debug Option| RunAway

    NextEnemy ==> EnemyMove
    EnemyMove ==> NextEnemy
    NextEnemy ==> EndTurn

    EndTurn ==> BeginTurn

    BeginPlayer --> |Can't Act| BeginPartner
    BeginPlayer ==> SwitchPlayer

    PlayerMove ==> EndPlayer

    EndPlayer --> |Turn Canceled| EndTurn
    EndPlayer --> |Hustled / Dipping| PrepareMenu1
    EndPlayer ==> BeginPartner

    BeginPartner --> |Can't Act| TransferTurn
    BeginPartner ==> SwitchPartner

    %% exists only as a sanity check in partner_move to ensure partner is not NULL
    %% PartnerMove --> |Invalid Partner| TransferTurn

    PartnerMove ==> EndPartner

    EndPartner ==> TransferTurn
    EndPartner -->|Turn Canceled| EndTurn

    TransferTurn --> SwitchPlayer
    TransferTurn --> SwitchPartner
    TransferTurn ==> NextEnemy

    SwitchPlayer ==> PrepareMenu1
    SwitchPartner ==> PrepareMenu2

    PrepareMenu1 ==> PlayerMenu
    PrepareMenu2 ==> PartnerMenu

    PlayerMenu --> |Can't Act / Do Nothing| EndPlayer
    PlayerMenu --> |Swap| SwitchPartner
    PlayerMenu --> |Single Option| PlayerMove
    PlayerMenu ===> SelectTarget1
    PlayerMenu --> ChangePartner1
    PlayerMenu --> RunAway
    PlayerMenu --> Defend
    Defend --> EndPlayer

    PartnerMenu --> |Can't Act| TransferTurn
    PartnerMenu --> |Swap| SwitchPlayer
    PartnerMenu ===> SelectTarget2
    PartnerMenu --> ChangePartner2
    PartnerMenu --> |Do Nothing| EndPartner

    %% exists in code, but not available in-game
    %% PartnerMenu --> RunAway

    SelectTarget1 ==>  PlayerMove
    SelectTarget1 --->  |Cancel| PlayerMenu

    ChangePartner1 --> |Quick Change| PrepareMenu1
    ChangePartner1 --> EndPlayer

    SelectTarget2 ==>  PartnerMove
    SelectTarget2 --->  |Cancel| PartnerMenu

    ChangePartner2 --> |Quick Change| PrepareMenu2
    ChangePartner2 --> EndPartner

    %% BATTLE END STATES

    EndDemo --> EndBattle
    EndTraining --> EndBattle

    RunAway --------> EndBattle
    RunAway --> |Failure| TransferTurn

    EnemiesDefeated --> Victory
    Victory --> |Skip Celebration| EndBattle
    Victory --> Celebration
    Celebration --> |Possible Level Up| EndBattle

    PlayerDefeated ---> Defeat
    Defeat --> EndBattle

    %% leave out all Peach-related complications
    %% EndPlayer --> |PEACH| TransferTurn
    %% BeginPlayer --> |PEACH| BeginPartner
    %% BeginPartner --> |PEACH| BeginPlayer
    %% PlayerMenu --> |PEACH| PeachMenu
    %% PartnerMenu --> |PEACH| TwinkMenu
    %% PeachMenu --> SelectTarget
    %% TwinkMenu --> SelectTarget
    %% TwinkMenu --> |Can't Act| EndPlayer
```
